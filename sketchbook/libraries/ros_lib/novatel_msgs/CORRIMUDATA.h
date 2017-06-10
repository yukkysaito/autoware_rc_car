#ifndef _ROS_novatel_msgs_CORRIMUDATA_h
#define _ROS_novatel_msgs_CORRIMUDATA_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "novatel_msgs/CommonHeader.h"

namespace novatel_msgs
{

  class CORRIMUDATA : public ros::Msg
  {
    public:
      novatel_msgs::CommonHeader header;
      int32_t week;
      float gpssec;
      float pitch_rate;
      float roll_rate;
      float yaw_rate;
      float x_accel;
      float y_accel;
      float z_accel;

    CORRIMUDATA():
      header(),
      week(0),
      gpssec(0),
      pitch_rate(0),
      roll_rate(0),
      yaw_rate(0),
      x_accel(0),
      y_accel(0),
      z_accel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_week;
      u_week.real = this->week;
      *(outbuffer + offset + 0) = (u_week.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_week.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_week.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_week.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->week);
      offset += serializeAvrFloat64(outbuffer + offset, this->gpssec);
      offset += serializeAvrFloat64(outbuffer + offset, this->pitch_rate);
      offset += serializeAvrFloat64(outbuffer + offset, this->roll_rate);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw_rate);
      offset += serializeAvrFloat64(outbuffer + offset, this->x_accel);
      offset += serializeAvrFloat64(outbuffer + offset, this->y_accel);
      offset += serializeAvrFloat64(outbuffer + offset, this->z_accel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_week;
      u_week.base = 0;
      u_week.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_week.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_week.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_week.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->week = u_week.real;
      offset += sizeof(this->week);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gpssec));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pitch_rate));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->roll_rate));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw_rate));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x_accel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y_accel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z_accel));
     return offset;
    }

    const char * getType(){ return "novatel_msgs/CORRIMUDATA"; };
    const char * getMD5(){ return "8ca3f26f898322425170fe621393f009"; };

  };

}
#endif