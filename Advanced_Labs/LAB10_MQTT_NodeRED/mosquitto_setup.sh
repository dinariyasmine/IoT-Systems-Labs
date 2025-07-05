#!/bin/bash
# On Windows: download and install from mosquitto.org/download/
# On Linux:
sudo apt update
sudo apt install -y mosquitto mosquitto-clients

# Configure Mosquitto (edit mosquitto.conf):
echo "listener 1883" | sudo tee -a /etc/mosquitto/mosquitto.conf
echo "allow_anonymous true" | sudo tee -a /etc/mosquitto/mosquitto.conf

# Restart Mosquitto service
sudo systemctl restart mosquitto