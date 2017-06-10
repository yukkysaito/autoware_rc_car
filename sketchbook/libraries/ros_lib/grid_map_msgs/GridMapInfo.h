#ifndef _ROS_grid_map_msgs_GridMapInfo_h
#define _ROS_grid_map_msgs_GridMapInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace grid_map_msgs
{

  class GridMapInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float resolution;
      float length_x;
      float length_y;
      geometry_msgs::Pose pose;

    GridMapInfo():
      header(),
      resolution(0),
      length_x(0),
      length_y(0),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->resolution);
      offset += serializeAvrFloat64(outbuffer + offset, this->length_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->length_y);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->resolution));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length_y));
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "grid_map_msgs/GridMapInfo"; };
    const char * getMD5(){ return "43ee5430e1c253682111cb6bedac0ef9"; };

  };

}
#endif