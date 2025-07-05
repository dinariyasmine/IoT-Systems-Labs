#!/bin/bash
# Update the Raspberry Pi
sudo apt update
sudo apt upgrade

# Install Python virtual environment
sudo apt install python3-venv

# Create a project folder
mkdir lab8
cd lab8

# Create and activate a virtual environment
python3 -m venv venv
source venv/bin/activate

# Install required Python libraries
pip install flask gpiozero

# Create templates directory
mkdir templates

echo "Setup complete! Now create the Python files and HTML template."
echo "To run the Flask server: python raspberry_pi_flask_server.py"