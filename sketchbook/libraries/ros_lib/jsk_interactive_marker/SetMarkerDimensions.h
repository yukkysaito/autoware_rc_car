#ifndef _ROS_SERVICE_SetMarkerDimensions_h
#define _ROS_SERVICE_SetMarkerDimensions_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_interactive_marker/MarkerDimensions.h"

namespace jsk_interactive_marker
{

static const char SETMARKERDIMENSIONS[] = "jsk_interactive_marker/SetMarkerDimensions";

  class SetMarkerDimensionsRequest : public ros::Msg
  {
    public:
      const char* target_name;
      jsk_interactive_marker::MarkerDimensions dimensions;

    SetMarkerDimensionsRequest():
      target_name(""),
      dimensions()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_target_name = strlen(this->target_name);
      memcpy(outbuffer + offset, &length_target_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->target_name, length_target_name);
      offset += length_target_name;
      offset += this->dimensions.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_target_name;
      memcpy(&length_target_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_name-1]=0;
      this->target_name = (char *)(inbuffer + offset-1);
      offset += length_target_name;
      offset += this->dimensions.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETMARKERDIMENSIONS; };
    const char * getMD5(){ return "68f212be16364271f11f516c3f033749"; };

  };

  class SetMarkerDimensionsResponse : public ros::Msg
  {
    public:

    SetMarkerDimensionsResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETMARKERDIMENSIONS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetMarkerDimensions {
    public:
    typedef SetMarkerDimensionsRequest Request;
    typedef SetMarkerDimensionsResponse Response;
  };

}
#endif
