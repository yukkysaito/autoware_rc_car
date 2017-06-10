#ifndef _ROS_jsk_gui_msgs_Tablet_h
#define _ROS_jsk_gui_msgs_Tablet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_gui_msgs/Action.h"
#include "jsk_gui_msgs/DeviceSensor.h"
#include "jsk_gui_msgs/Touch.h"

namespace jsk_gui_msgs
{

  class Tablet : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* hardware_name;
      const char* hardware_id;
      jsk_gui_msgs::Action action;
      jsk_gui_msgs::DeviceSensor sensor;
      uint8_t touches_length;
      jsk_gui_msgs::Touch st_touches;
      jsk_gui_msgs::Touch * touches;

    Tablet():
      header(),
      hardware_name(""),
      hardware_id(""),
      action(),
      sensor(),
      touches_length(0), touches(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_hardware_name = strlen(this->hardware_name);
      memcpy(outbuffer + offset, &length_hardware_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->hardware_name, length_hardware_name);
      offset += length_hardware_name;
      uint32_t length_hardware_id = strlen(this->hardware_id);
      memcpy(outbuffer + offset, &length_hardware_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->hardware_id, length_hardware_id);
      offset += length_hardware_id;
      offset += this->action.serialize(outbuffer + offset);
      offset += this->sensor.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_hardware_name;
      memcpy(&length_hardware_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hardware_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hardware_name-1]=0;
      this->hardware_name = (char *)(inbuffer + offset-1);
      offset += length_hardware_name;
      uint32_t length_hardware_id;
      memcpy(&length_hardware_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hardware_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hardware_id-1]=0;
      this->hardware_id = (char *)(inbuffer + offset-1);
      offset += length_hardware_id;
      offset += this->action.deserialize(inbuffer + offset);
      offset += this->sensor.deserialize(inbuffer + offset);
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

    const char * getType(){ return "jsk_gui_msgs/Tablet"; };
    const char * getMD5(){ return "0bab196c7b214826d8c27d7bd5f924f6"; };

  };

}
#endif