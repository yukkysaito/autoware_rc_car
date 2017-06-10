#ifndef _ROS_jsk_interactive_marker_MoveModel_h
#define _ROS_jsk_interactive_marker_MoveModel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/JointState.h"
#include "geometry_msgs/PoseStamped.h"

namespace jsk_interactive_marker
{

  class MoveModel : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* name;
      const char* description;
      sensor_msgs::JointState joint_state_origin;
      sensor_msgs::JointState joint_state_goal;
      geometry_msgs::PoseStamped pose_origin;
      geometry_msgs::PoseStamped pose_goal;

    MoveModel():
      header(),
      name(""),
      description(""),
      joint_state_origin(),
      joint_state_goal(),
      pose_origin(),
      pose_goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_description = strlen(this->description);
      memcpy(outbuffer + offset, &length_description, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      offset += this->joint_state_origin.serialize(outbuffer + offset);
      offset += this->joint_state_goal.serialize(outbuffer + offset);
      offset += this->pose_origin.serialize(outbuffer + offset);
      offset += this->pose_goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_description;
      memcpy(&length_description, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      offset += this->joint_state_origin.deserialize(inbuffer + offset);
      offset += this->joint_state_goal.deserialize(inbuffer + offset);
      offset += this->pose_origin.deserialize(inbuffer + offset);
      offset += this->pose_goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_interactive_marker/MoveModel"; };
    const char * getMD5(){ return "61edcddd6ca50e876e68d4fcf06c90f6"; };

  };

}
#endif