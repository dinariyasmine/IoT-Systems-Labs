#!/bin/bash
# Install Node.js and npm first
# Then install Node-RED:
npm install -g --unsafe-perm node-red

# Start Node-RED:
node-red

# Install dashboard nodes:
cd ~/.node-red
npm install node-red-dashboard