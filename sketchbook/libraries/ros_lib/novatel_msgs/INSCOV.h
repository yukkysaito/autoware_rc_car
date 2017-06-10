#ifndef _ROS_novatel_msgs_INSCOV_h
#define _ROS_novatel_msgs_INSCOV_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "novatel_msgs/CommonHeader.h"

namespace novatel_msgs
{

  class INSCOV : public ros::Msg
  {
    public:
      novatel_msgs::CommonHeader header;
      int32_t week;
      float gpssec;
      float pos11;
      float pos12;
      float pos13;
      float pos21;
      float pos22;
      float pos23;
      float pos31;
      float pos32;
      float pos33;
      float att11;
      float att12;
      float att13;
      float att21;
      float att22;
      float att23;
      float att31;
      float att32;
      float att33;
      float vel11;
      float vel12;
      float vel13;
      float vel21;
      float vel22;
      float vel23;
      float vel31;
      float vel32;
      float vel33;

    INSCOV():
      header(),
      week(0),
      gpssec(0),
      pos11(0),
      pos12(0),
      pos13(0),
      pos21(0),
      pos22(0),
      pos23(0),
      pos31(0),
      pos32(0),
      pos33(0),
      att11(0),
      att12(0),
      att13(0),
      att21(0),
      att22(0),
      att23(0),
      att31(0),
      att32(0),
      att33(0),
      vel11(0),
      vel12(0),
      vel13(0),
      vel21(0),
      vel22(0),
      vel23(0),
      vel31(0),
      vel32(0),
      vel33(0)
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
      offset += serializeAvrFloat64(outbuffer + offset, this->pos11);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos12);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos13);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos21);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos22);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos23);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos31);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos32);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos33);
      offset += serializeAvrFloat64(outbuffer + offset, this->att11);
      offset += serializeAvrFloat64(outbuffer + offset, this->att12);
      offset += serializeAvrFloat64(outbuffer + offset, this->att13);
      offset += serializeAvrFloat64(outbuffer + offset, this->att21);
      offset += serializeAvrFloat64(outbuffer + offset, this->att22);
      offset += serializeAvrFloat64(outbuffer + offset, this->att23);
      offset += serializeAvrFloat64(outbuffer + offset, this->att31);
      offset += serializeAvrFloat64(outbuffer + offset, this->att32);
      offset += serializeAvrFloat64(outbuffer + offset, this->att33);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel11);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel12);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel13);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel21);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel22);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel23);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel31);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel32);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel33);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos11));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos12));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos13));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos21));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos22));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos23));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos31));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos32));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos33));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->att11));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->att12));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->att13));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->att21));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->att22));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->att23));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->att31));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->att32));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->att33));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel11));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel12));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel13));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel21));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel22));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel23));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel31));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel32));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel33));
     return offset;
    }

    const char * getType(){ return "novatel_msgs/INSCOV"; };
    const char * getMD5(){ return "75d77cf9321af3888caeeab3a756d0ac"; };

  };

}
#endif