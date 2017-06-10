#ifndef _ROS_jsk_hark_msgs_HarkPower_h
#define _ROS_jsk_hark_msgs_HarkPower_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_hark_msgs
{

  class HarkPower : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t count;
      int32_t directions;
      int32_t data_bytes;
      uint8_t powers_length;
      float st_powers;
      float * powers;

    HarkPower():
      header(),
      count(0),
      directions(0),
      data_bytes(0),
      powers_length(0), powers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_count;
      u_count.real = this->count;
      *(outbuffer + offset + 0) = (u_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_count.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->count);
      union {
        int32_t real;
        uint32_t base;
      } u_directions;
      u_directions.real = this->directions;
      *(outbuffer + offset + 0) = (u_directions.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_directions.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_directions.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_directions.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->directions);
      union {
        int32_t real;
        uint32_t base;
      } u_data_bytes;
      u_data_bytes.real = this->data_bytes;
      *(outbuffer + offset + 0) = (u_data_bytes.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data_bytes.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_data_bytes.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_data_bytes.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_bytes);
      *(outbuffer + offset++) = powers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < powers_length; i++){
      union {
        float real;
        uint32_t base;
      } u_powersi;
      u_powersi.real = this->powers[i];
      *(outbuffer + offset + 0) = (u_powersi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_powersi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_powersi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_powersi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->powers[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_count;
      u_count.base = 0;
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->count = u_count.real;
      offset += sizeof(this->count);
      union {
        int32_t real;
        uint32_t base;
      } u_directions;
      u_directions.base = 0;
      u_directions.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_directions.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_directions.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_directions.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->directions = u_directions.real;
      offset += sizeof(this->directions);
      union {
        int32_t real;
        uint32_t base;
      } u_data_bytes;
      u_data_bytes.base = 0;
      u_data_bytes.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data_bytes.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_data_bytes.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_data_bytes.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->data_bytes = u_data_bytes.real;
      offset += sizeof(this->data_bytes);
      uint8_t powers_lengthT = *(inbuffer + offset++);
      if(powers_lengthT > powers_length)
        this->powers = (float*)realloc(this->powers, powers_lengthT * sizeof(float));
      offset += 3;
      powers_length = powers_lengthT;
      for( uint8_t i = 0; i < powers_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_powers;
      u_st_powers.base = 0;
      u_st_powers.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_powers.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_powers.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_powers.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_powers = u_st_powers.real;
      offset += sizeof(this->st_powers);
        memcpy( &(this->powers[i]), &(this->st_powers), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "jsk_hark_msgs/HarkPower"; };
    const char * getMD5(){ return "251c13d7a8be27144a2b24c6f53df705"; };

  };

}
#endif