# Import necessary libraries
import smbus2 # For I2C communication with ADS1115
import time # For delays
from gpiozero import PWMLED # For controlling LED brightness (PWM)

# Set up the LED on GPIO 18 (supports PWM)
ledPin = PWMLED(18)

# Set up I2C bus and ADS1115 address
I2C_BUS = 1 # I2C bus number on Raspberry Pi
ADS1115_ADDRESS = 0x48 # Default I2C address for ADS1115
bus = smbus2.SMBus(I2C_BUS) # Create an I2C bus object

# ADS1115 register addresses
ADS1115_CONVERSION = 0x00 # Register to read ADC value
ADS1115_CONFIG = 0x01 # Register to configure ADC

# Function to configure the ADS1115
def initialize_ads1115():
    # Build config value for single-ended AIN0, gain, mode, and data rate
    config = (
        (0x40 << 8) # Select channel AIN0
        | (0x04 << 8) # Set gain to ±4.096V
        | (0x80) # Continuous conversion mode
        | (0x03) # Data rate: 128 samples/sec
    )
    config_bytes = [config >> 8, config & 0xFF] # Split config into two bytes
    bus.write_i2c_block_data(ADS1115_ADDRESS, ADS1115_CONFIG, config_bytes) # Send config

# Function to read a value from the ADS1115
def read_ads1115():
    result = bus.read_i2c_block_data(ADS1115_ADDRESS, ADS1115_CONVERSION, 2) # Read 2 bytes
    raw_value = (result[0] << 8) | result[1] # Combine bytes to get 16-bit value
    if raw_value > 0x7FFF: # Convert to signed number if needed
        raw_value -= 0x10000
    return raw_value

# Initialize the ADS1115
initialize_ads1115()

# Main loop
try:
    while True:
        ldr_raw = read_ads1115() # Read value from LDR
        print(f"LDR Raw Value: {ldr_raw}") # Print the value

        # Convert raw value (-32768 to +32767) to range 0.0 to 1.0 for PWM
        brightness = (ldr_raw + 32768) / 65535
        print(f"LED Brightness: {brightness:.2f}") # Print brightness

        ledPin.value = brightness # Set LED brightness

        time.sleep(0.5) # Wait before next reading

except KeyboardInterrupt:
    print("Exiting...")

finally:
    bus.close() # Close the I2C bus when done