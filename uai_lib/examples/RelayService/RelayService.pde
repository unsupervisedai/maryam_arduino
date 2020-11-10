/*
 * Turn ON/OFF a relay from service
 */

#include <ros.h>
#include <uai_lib.h>
#include <unsupervised_msgs/NavigatorCmd.h>

#define ARDUINO_SRV_NAME "relay_srv"
#define NODE_PERIOD_MS 100
#define RELAY_PIN 50

ros::NodeHandle  nh;
using unsupervised_msgs::NavigatorCmd;

void setupRelay() {
  pinMode(RELAY_PIN, OUTPUT);
  relayActivate(false);
}

void relayActivate(bool relayOn) {
  if (relayOn)
  {
    digitalWrite(RELAY_PIN, LOW);
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);
  }
}

void callback(const NavigatorCmd::Request & req, NavigatorCmd::Response & res){
  if (strcmp(req.trigger, "on") == 0)
  {
    relayActivate(true);
    res.new_state = "on";
  }
  else {
    relayActivate(false);
    res.new_state = "off";
  }
  res.result = res.SUCCESS;
}

ros::ServiceServer<NavigatorCmd::Request, NavigatorCmd::Response> srv(ARDUINO_SRV_NAME, &callback);

void setup()
{
  setupRelay();
  nh.initNode();
  nh.advertiseService(srv);
}

void loop()
{
  nh.spinOnce();
  delay(NODE_PERIOD_MS);
}

