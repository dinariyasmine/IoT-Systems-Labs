from flask import Flask, render_template
from gpiozero import LED

app = Flask(__name__)
led = LED(21)  # GPIO pin 21

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/on')
def led_on():
    led.on()
    return render_template('index.html', status="LED is ON")

@app.route('/off')
def led_off():
    led.off()
    return render_template('index.html', status="LED is OFF")

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)