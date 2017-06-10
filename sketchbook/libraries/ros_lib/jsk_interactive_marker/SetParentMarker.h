#ifndef _ROS_SERVICE_SetParentMarker_h
#define _ROS_SERVICE_SetParentMarker_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_interactive_marker
{

static const char SETPARENTMARKER[] = "jsk_interactive_marker/SetParentMarker";

  class SetParentMarkerRequest : public ros::Msg
  {
    public:
      const char* parent_topic_name;
      const char* parent_marker_name;
      const char* child_marker_name;

    SetParentMarkerRequest():
      parent_topic_name(""),
      parent_marker_name(""),
      child_marker_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_parent_topic_name = strlen(this->parent_topic_name);
      memcpy(outbuffer + offset, &length_parent_topic_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->parent_topic_name, length_parent_topic_name);
      offset += length_parent_topic_name;
      uint32_t length_parent_marker_name = strlen(this->parent_marker_name);
      memcpy(outbuffer + offset, &length_parent_marker_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->parent_marker_name, length_parent_marker_name);
      offset += length_parent_marker_name;
      uint32_t length_child_marker_name = strlen(this->child_marker_name);
      memcpy(outbuffer + offset, &length_child_marker_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->child_marker_name, length_child_marker_name);
      offset += length_child_marker_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_parent_topic_name;
      memcpy(&length_parent_topic_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parent_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parent_topic_name-1]=0;
      this->parent_topic_name = (char *)(inbuffer + offset-1);
      offset += length_parent_topic_name;
      uint32_t length_parent_marker_name;
      memcpy(&length_parent_marker_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parent_marker_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parent_marker_name-1]=0;
      this->parent_marker_name = (char *)(inbuffer + offset-1);
      offset += length_parent_marker_name;
      uint32_t length_child_marker_name;
      memcpy(&length_child_marker_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_child_marker_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_child_marker_name-1]=0;
      this->child_marker_name = (char *)(inbuffer + offset-1);
      offset += length_child_marker_name;
     return offset;
    }

    const char * getType(){ return SETPARENTMARKER; };
    const char * getMD5(){ return "0fbeb5790154b3ebc3c1cc4917de6fcc"; };

  };

  class SetParentMarkerResponse : public ros::Msg
  {
    public:

    SetParentMarkerResponse()
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

    const char * getType(){ return SETPARENTMARKER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetParentMarker {
    public:
    typedef SetParentMarkerRequest Request;
    typedef SetParentMarkerResponse Response;
  };

}
#endif
