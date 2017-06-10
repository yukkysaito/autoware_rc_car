#ifndef _ROS_SERVICE_MarkerSetPose_h
#define _ROS_SERVICE_MarkerSetPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "visualization_msgs/Marker.h"

namespace jsk_interactive_marker
{

static const char MARKERSETPOSE[] = "jsk_interactive_marker/MarkerSetPose";

  class MarkerSetPoseRequest : public ros::Msg
  {
    public:
      const char* marker_name;
      geometry_msgs::PoseStamped pose;
      uint8_t markers_length;
      visualization_msgs::Marker st_markers;
      visualization_msgs::Marker * markers;

    MarkerSetPoseRequest():
      marker_name(""),
      pose(),
      markers_length(0), markers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_marker_name = strlen(this->marker_name);
      memcpy(outbuffer + offset, &length_marker_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->marker_name, length_marker_name);
      offset += length_marker_name;
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = markers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_marker_name;
      memcpy(&length_marker_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_marker_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_marker_name-1]=0;
      this->marker_name = (char *)(inbuffer + offset-1);
      offset += length_marker_name;
      offset += this->pose.deserialize(inbuffer + offset);
      uint8_t markers_lengthT = *(inbuffer + offset++);
      if(markers_lengthT > markers_length)
        this->markers = (visualization_msgs::Marker*)realloc(this->markers, markers_lengthT * sizeof(visualization_msgs::Marker));
      offset += 3;
      markers_length = markers_lengthT;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->st_markers.deserialize(inbuffer + offset);
        memcpy( &(this->markers[i]), &(this->st_markers), sizeof(visualization_msgs::Marker));
      }
     return offset;
    }

    const char * getType(){ return MARKERSETPOSE; };
    const char * getMD5(){ return "5fa9dd39bbd60c526a940a2b87972e58"; };

  };

  class MarkerSetPoseResponse : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;

    MarkerSetPoseResponse():
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MARKERSETPOSE; };
    const char * getMD5(){ return "3f8930d968a3e84d471dff917bb1cdae"; };

  };

  class MarkerSetPose {
    public:
    typedef MarkerSetPoseRequest Request;
    typedef MarkerSetPoseResponse Response;
  };

}
#endif
