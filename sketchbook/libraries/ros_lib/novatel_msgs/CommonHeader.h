#ifndef _ROS_novatel_msgs_CommonHeader_h
#define _ROS_novatel_msgs_CommonHeader_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace novatel_msgs
{

  class CommonHeader : public ros::Msg
  {
    public:
      uint16_t id;
      uint8_t msg_type;
      uint8_t port_addr;
      uint16_t length;
      uint16_t sequence;
      uint8_t idle_time;
      uint8_t time_status;
      uint16_t gps_week;
      uint32_t gps_week_seconds;
      uint32_t receiver_status;
      uint16_t reserved;
      uint16_t software_version;
      enum { RECEIVER_STATUS_ERROR = 1 };
      enum { RECEIVER_STATUS_TEMPERATURE_WARNING = 2 };
      enum { RECEIVER_STATUS_VOLTAGE_SUPPLY_WARNING = 4 };
      enum { RECEIVER_STATUS_ANTENNA_UNPOWERED = 8 };
      enum { RECEIVER_STATUS_LNA_FAILURE = 16 };
      enum { RECEIVER_STATUS_ANTENNA_OPEN = 32 };
      enum { RECEIVER_STATUS_ANTENNA_SHORTED = 64 };
      enum { RECEIVER_STATUS_CPU_OVERLOADED = 128 };
      enum { RECEIVER_STATUS_COM1_BUFFER_OVERRUN = 256 };
      enum { RECEIVER_STATUS_COM2_BUFFER_OVERRUN = 512 };
      enum { RECEIVER_STATUS_COM3_BUFFER_OVERRUN = 1024 };
      enum { RECEIVER_STATUS_LINK_OVERLOAD = 2048 };
      enum { RECEIVER_STATUS_AUX_TRANSMIT_OVERRUN = 8192 };
      enum { RECEIVER_STATUS_AGC_OUT_OF_RANGE = 16384 };
      enum { RECEIVER_STATUS_INS_RESET = 65536 };
      enum { RECEIVER_STATUS_ALMANAC_INVALID = 262144 };
      enum { RECEIVER_STATUS_POSITION_SOLUTION_INVALID = 524288 };
      enum { RECEIVER_STATUS_POSITION_NOT_FIXED = 1048576 };
      enum { RECEIVER_STATUS_CLOCK_STEERING_DISABLED = 2097152 };
      enum { RECEIVER_STATUS_CLOCK_MODEL_INVALID = 4194304 };
      enum { RECEIVER_STATUS_EXTERNAL_OSCILLATOR_LOCKED = 8388608 };
      enum { RECEIVER_STATUS_SOFTWARE_RESOURCE_WARNING = 16777216 };
      enum { RECEIVER_STATUS_AUXILIARY3_EVENT = 536870912 };
      enum { RECEIVER_STATUS_AUXILIARY2_EVENT = 1073741824 };
      enum { RECEIVER_STATUS_AUXILIARY1_EVENT = 2147483648 };

    CommonHeader():
      id(0),
      msg_type(0),
      port_addr(0),
      length(0),
      sequence(0),
      idle_time(0),
      time_status(0),
      gps_week(0),
      gps_week_seconds(0),
      receiver_status(0),
      reserved(0),
      software_version(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->msg_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->msg_type);
      *(outbuffer + offset + 0) = (this->port_addr >> (8 * 0)) & 0xFF;
      offset += sizeof(this->port_addr);
      *(outbuffer + offset + 0) = (this->length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->length >> (8 * 1)) & 0xFF;
      offset += sizeof(this->length);
      *(outbuffer + offset + 0) = (this->sequence >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sequence >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sequence);
      *(outbuffer + offset + 0) = (this->idle_time >> (8 * 0)) & 0xFF;
      offset += sizeof(this->idle_time);
      *(outbuffer + offset + 0) = (this->time_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->time_status);
      *(outbuffer + offset + 0) = (this->gps_week >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gps_week >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gps_week);
      *(outbuffer + offset + 0) = (this->gps_week_seconds >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gps_week_seconds >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gps_week_seconds >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gps_week_seconds >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gps_week_seconds);
      *(outbuffer + offset + 0) = (this->receiver_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->receiver_status >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->receiver_status >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->receiver_status >> (8 * 3)) & 0xFF;
      offset += sizeof(this->receiver_status);
      *(outbuffer + offset + 0) = (this->reserved >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reserved >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reserved);
      *(outbuffer + offset + 0) = (this->software_version >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->software_version >> (8 * 1)) & 0xFF;
      offset += sizeof(this->software_version);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint16_t) (*(inbuffer + offset)));
      this->id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->id);
      this->msg_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->msg_type);
      this->port_addr =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->port_addr);
      this->length =  ((uint16_t) (*(inbuffer + offset)));
      this->length |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->length);
      this->sequence =  ((uint16_t) (*(inbuffer + offset)));
      this->sequence |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sequence);
      this->idle_time =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->idle_time);
      this->time_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->time_status);
      this->gps_week =  ((uint16_t) (*(inbuffer + offset)));
      this->gps_week |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->gps_week);
      this->gps_week_seconds =  ((uint32_t) (*(inbuffer + offset)));
      this->gps_week_seconds |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gps_week_seconds |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->gps_week_seconds |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->gps_week_seconds);
      this->receiver_status =  ((uint32_t) (*(inbuffer + offset)));
      this->receiver_status |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->receiver_status |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->receiver_status |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->receiver_status);
      this->reserved =  ((uint16_t) (*(inbuffer + offset)));
      this->reserved |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reserved);
      this->software_version =  ((uint16_t) (*(inbuffer + offset)));
      this->software_version |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->software_version);
     return offset;
    }

    const char * getType(){ return "novatel_msgs/CommonHeader"; };
    const char * getMD5(){ return "9e2cebab6fb8a68faebdd0703445eea6"; };

  };

}
#endif