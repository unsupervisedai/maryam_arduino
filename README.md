# maryam_arduino
Public repo with useful arduino firmware for integration to Maryam.

## Installation

### Pre-requirements

* Install [Arduino IDE](https://www.arduino.cc/en/Guide) if you don't have it already

For development and tests with your laptop (Linux laptop is required):

* Install ROS
* Install [rosserial_python](http://wiki.ros.org/rosserial_python)


### Install Arduino libraries

Locate your Arduino home folder <arduino_home> (for Linux this is usually `~/Arduino`)
Copy the folders `ros_lib` and `uai_lib` in the arduino libraries folder (<arduino_home>/libraries)

## Firmware, upload and test

You can create a firmware with a NavigatorCmd service the arduino can receive to execute an action.

NavigatorCmd is defined as follows:
```
string trigger
---
int8 SUCCESS=0
int8 FAIL=1
int8 result
string new_state
```

### Example: run BlinkService from uai_lib

* Open Arduino IDE
* Open the BlinkService sketch (File > Examples > uai_lib > BlinkService)
* Connect your Arduino to your computer
* Click on "Upload" and wait the firmware is flashed

To control the arduino blink from your laptop (ros and rosserial_python package is required):
* Open a terminal and launch `roscore`
* Open another terminal and launch `rosrun rosserial_python serial_node.py` to communicate between roscore and the arduino
* Open another terminal and launch `rosservice call /arduino_srv "trigger: 'on'"` to turn on the light or `rosservice call /arduino_srv "trigger: 'off'"` to turn off the light

You can also try the other examples:
* RelayService

And to create your own firmware, take BlinkService as example and adapt the code (`ARDUINO_SRV_NAME`, `NODE_PERIOD_MS`, `callback` function)


