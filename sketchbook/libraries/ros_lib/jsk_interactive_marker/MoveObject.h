#ifndef _ROS_jsk_interactive_marker_MoveObject_h
#define _ROS_jsk_interactive_marker_MoveObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Pose.h"

namespace jsk_interactive_marker
{

  class MoveObject : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped origin;
      geometry_msgs::PoseStamped goal;
      geometry_msgs::Pose graspPose;

    MoveObject():
      origin(),
      goal(),
      graspPose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->origin.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      offset += this->graspPose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->origin.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
      offset += this->graspPose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_interactive_marker/MoveObject"; };
    const char * getMD5(){ return "398be7a942bfa9cfc119a5f96e3dc37a"; };

  };

}
#endif