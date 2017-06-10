#ifndef _ROS_jsk_interactive_marker_JointTrajectoryPointWithType_h
#define _ROS_jsk_interactive_marker_JointTrajectoryPointWithType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace jsk_interactive_marker
{

  class JointTrajectoryPointWithType : public ros::Msg
  {
    public:
      int8_t type;
      const char* args;
      bool wait;
      uint8_t positions_length;
      float st_positions;
      float * positions;
      uint8_t velocities_length;
      float st_velocities;
      float * velocities;
      uint8_t accelerations_length;
      float st_accelerations;
      float * accelerations;
      uint8_t effort_length;
      float st_effort;
      float * effort;
      ros::Duration time_from_start;
      enum { JOINT_INTERPOLATION = 0 };
      enum { LINEAR_INTERPOLATION = 1 };
      enum { COLLISION_AVOIDANCE = 2 };
      enum { CLOSE_HAND = 10 };
      enum { OPEN_HAND = 11 };

    JointTrajectoryPointWithType():
      type(0),
      args(""),
      wait(0),
      positions_length(0), positions(NULL),
      velocities_length(0), velocities(NULL),
      accelerations_length(0), accelerations(NULL),
      effort_length(0), effort(NULL),
      time_from_start()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_args = strlen(this->args);
      memcpy(outbuffer + offset, &length_args, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->args, length_args);
      offset += length_args;
      union {
        bool real;
        uint8_t base;
      } u_wait;
      u_wait.real = this->wait;
      *(outbuffer + offset + 0) = (u_wait.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wait);
      *(outbuffer + offset++) = positions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < positions_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->positions[i]);
      }
      *(outbuffer + offset++) = velocities_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < velocities_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocities[i]);
      }
      *(outbuffer + offset++) = accelerations_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < accelerations_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->accelerations[i]);
      }
      *(outbuffer + offset++) = effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < effort_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->effort[i]);
      }
      *(outbuffer + offset + 0) = (this->time_from_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.sec);
      *(outbuffer + offset + 0) = (this->time_from_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
      offset += sizeof(this->type);
      uint32_t length_args;
      memcpy(&length_args, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_args; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_args-1]=0;
      this->args = (char *)(inbuffer + offset-1);
      offset += length_args;
      union {
        bool real;
        uint8_t base;
      } u_wait;
      u_wait.base = 0;
      u_wait.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wait = u_wait.real;
      offset += sizeof(this->wait);
      uint8_t positions_lengthT = *(inbuffer + offset++);
      if(positions_lengthT > positions_length)
        this->positions = (float*)realloc(this->positions, positions_lengthT * sizeof(float));
      offset += 3;
      positions_length = positions_lengthT;
      for( uint8_t i = 0; i < positions_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_positions));
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(float));
      }
      uint8_t velocities_lengthT = *(inbuffer + offset++);
      if(velocities_lengthT > velocities_length)
        this->velocities = (float*)realloc(this->velocities, velocities_lengthT * sizeof(float));
      offset += 3;
      velocities_length = velocities_lengthT;
      for( uint8_t i = 0; i < velocities_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_velocities));
        memcpy( &(this->velocities[i]), &(this->st_velocities), sizeof(float));
      }
      uint8_t accelerations_lengthT = *(inbuffer + offset++);
      if(accelerations_lengthT > accelerations_length)
        this->accelerations = (float*)realloc(this->accelerations, accelerations_lengthT * sizeof(float));
      offset += 3;
      accelerations_length = accelerations_lengthT;
      for( uint8_t i = 0; i < accelerations_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_accelerations));
        memcpy( &(this->accelerations[i]), &(this->st_accelerations), sizeof(float));
      }
      uint8_t effort_lengthT = *(inbuffer + offset++);
      if(effort_lengthT > effort_length)
        this->effort = (float*)realloc(this->effort, effort_lengthT * sizeof(float));
      offset += 3;
      effort_length = effort_lengthT;
      for( uint8_t i = 0; i < effort_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_effort));
        memcpy( &(this->effort[i]), &(this->st_effort), sizeof(float));
      }
      this->time_from_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.sec);
      this->time_from_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.nsec);
     return offset;
    }

    const char * getType(){ return "jsk_interactive_marker/JointTrajectoryPointWithType"; };
    const char * getMD5(){ return "990bd6a1d9e03cc634e576f569783816"; };

  };

}
#endif