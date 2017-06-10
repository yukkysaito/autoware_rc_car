#ifndef _ROS_SERVICE_GetTransformableMarkerFocus_h
#define _ROS_SERVICE_GetTransformableMarkerFocus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_interactive_marker
{

static const char GETTRANSFORMABLEMARKERFOCUS[] = "jsk_interactive_marker/GetTransformableMarkerFocus";

  class GetTransformableMarkerFocusRequest : public ros::Msg
  {
    public:

    GetTransformableMarkerFocusRequest()
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

    const char * getType(){ return GETTRANSFORMABLEMARKERFOCUS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetTransformableMarkerFocusResponse : public ros::Msg
  {
    public:
      const char* target_name;

    GetTransformableMarkerFocusResponse():
      target_name("")
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
     return offset;
    }

    const char * getType(){ return GETTRANSFORMABLEMARKERFOCUS; };
    const char * getMD5(){ return "2008933b3c7227647cbe00c74682331a"; };

  };

  class GetTransformableMarkerFocus {
    public:
    typedef GetTransformableMarkerFocusRequest Request;
    typedef GetTransformableMarkerFocusResponse Response;
  };

}
#endif
