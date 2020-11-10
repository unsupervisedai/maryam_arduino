#ifndef _ROS_SERVICE_NavigatorCmd_h
#define _ROS_SERVICE_NavigatorCmd_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace unsupervised_msgs
{

static const char NAVIGATORCMD[] = "unsupervised_msgs/NavigatorCmd";

  class NavigatorCmdRequest : public ros::Msg
  {
    public:
      typedef const char* _trigger_type;
      _trigger_type trigger;

    NavigatorCmdRequest():
      trigger("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_trigger = strlen(this->trigger);
      varToArr(outbuffer + offset, length_trigger);
      offset += 4;
      memcpy(outbuffer + offset, this->trigger, length_trigger);
      offset += length_trigger;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_trigger;
      arrToVar(length_trigger, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_trigger; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_trigger-1]=0;
      this->trigger = (char *)(inbuffer + offset-1);
      offset += length_trigger;
     return offset;
    }

    const char * getType(){ return NAVIGATORCMD; };
    const char * getMD5(){ return "90b35ea27ddf357f57c0d8bf8e94ea7f"; };

  };

  class NavigatorCmdResponse : public ros::Msg
  {
    public:
      typedef int8_t _result_type;
      _result_type result;
      typedef const char* _new_state_type;
      _new_state_type new_state;
      enum { SUCCESS = 0 };
      enum { FAIL = 1 };

    NavigatorCmdResponse():
      result(0),
      new_state("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      uint32_t length_new_state = strlen(this->new_state);
      varToArr(outbuffer + offset, length_new_state);
      offset += 4;
      memcpy(outbuffer + offset, this->new_state, length_new_state);
      offset += length_new_state;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
      uint32_t length_new_state;
      arrToVar(length_new_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_new_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_new_state-1]=0;
      this->new_state = (char *)(inbuffer + offset-1);
      offset += length_new_state;
     return offset;
    }

    const char * getType(){ return NAVIGATORCMD; };
    const char * getMD5(){ return "d968c41cbe570ac5aec8f5e45414bf20"; };

  };

  class NavigatorCmd {
    public:
    typedef NavigatorCmdRequest Request;
    typedef NavigatorCmdResponse Response;
  };

}
#endif
