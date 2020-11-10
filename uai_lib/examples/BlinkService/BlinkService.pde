/*
 * blink from service
 */

#include <ros.h>
#include <uai_lib.h>
#include <unsupervised_msgs/NavigatorCmd.h>

#define ARDUINO_SRV_NAME "arduino_srv"
#define NODE_PERIOD_MS 100

ros::NodeHandle  nh;
using unsupervised_msgs::NavigatorCmd;

void setupBlink() {
  pinMode(LED_BUILTIN, OUTPUT);
  blink(false);
}

void blink(bool lightOn) {
  if (lightOn)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void callback(const NavigatorCmd::Request & req, NavigatorCmd::Response & res){
  if (strcmp(req.trigger, "on") == 0)
  {
    blink(true);
    res.new_state = "on";
  }
  else {
    blink(false);
    res.new_state = "off";
  }
  res.result = res.SUCCESS;
}

ros::ServiceServer<NavigatorCmd::Request, NavigatorCmd::Response> srv(ARDUINO_SRV_NAME, &callback);

void setup()
{
  setupBlink();
  nh.initNode();
  nh.advertiseService(srv);
}

void loop()
{
  nh.spinOnce();
  delay(NODE_PERIOD_MS);
}

