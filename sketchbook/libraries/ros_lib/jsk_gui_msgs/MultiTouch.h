#ifndef _ROS_jsk_gui_msgs_MultiTouch_h
#define _ROS_jsk_gui_msgs_MultiTouch_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_gui_msgs/Touch.h"

namespace jsk_gui_msgs
{

  class MultiTouch : public ros::Msg
  {
    public:
      uint8_t touches_length;
      jsk_gui_msgs::Touch st_touches;
      jsk_gui_msgs::Touch * touches;

    MultiTouch():
      touches_length(0), touches(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = touches_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < touches_length; i++){
      offset += this->touches[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t touches_lengthT = *(inbuffer + offset++);
      if(touches_lengthT > touches_length)
        this->touches = (jsk_gui_msgs::Touch*)realloc(this->touches, touches_lengthT * sizeof(jsk_gui_msgs::Touch));
      offset += 3;
      touches_length = touches_lengthT;
      for( uint8_t i = 0; i < touches_length; i++){
      offset += this->st_touches.deserialize(inbuffer + offset);
        memcpy( &(this->touches[i]), &(this->st_touches), sizeof(jsk_gui_msgs::Touch));
      }
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/MultiTouch"; };
    const char * getMD5(){ return "9f4a309588ef669e69a71aa5601ea65e"; };

  };

}
#endif