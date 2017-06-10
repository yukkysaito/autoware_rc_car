#ifndef _ROS_jsk_interactive_marker_SnapFootPrintInput_h
#define _ROS_jsk_interactive_marker_SnapFootPrintInput_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Pose.h"

namespace jsk_interactive_marker
{

  class SnapFootPrintInput : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped input_pose;
      geometry_msgs::Pose lleg_pose;
      geometry_msgs::Pose rleg_pose;

    SnapFootPrintInput():
      input_pose(),
      lleg_pose(),
      rleg_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->input_pose.serialize(outbuffer + offset);
      offset += this->lleg_pose.serialize(outbuffer + offset);
      offset += this->rleg_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->input_pose.deserialize(inbuffer + offset);
      offset += this->lleg_pose.deserialize(inbuffer + offset);
      offset += this->rleg_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_interactive_marker/SnapFootPrintInput"; };
    const char * getMD5(){ return "07fc9b79352f12bc13742f589662de86"; };

  };

}
#endif