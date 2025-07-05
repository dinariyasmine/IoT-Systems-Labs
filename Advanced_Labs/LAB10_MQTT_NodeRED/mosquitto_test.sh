#!/bin/bash
# In one terminal, subscribe to topics:
mosquitto_sub -h localhost -t arduino/force -t arduino/ldr

# In another terminal, publish test messages:
# mosquitto_pub -h localhost -t arduino/force -m "100"
# mosquitto_pub -h localhost -t arduino/ldr -m "500"