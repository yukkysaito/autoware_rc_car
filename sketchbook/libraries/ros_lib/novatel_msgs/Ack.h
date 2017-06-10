#ifndef _ROS_novatel_msgs_Ack_h
#define _ROS_novatel_msgs_Ack_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace novatel_msgs
{

  class Ack : public ros::Msg
  {
    public:
      uint16_t transaction;
      uint16_t id;
      uint16_t response_code;
      uint8_t params_status;
      uint8_t error_parameter_name[32];
      enum { RESPONSE_NOT_APPLICABLE = 0 };
      enum { RESPONSE_ACCEPTED = 1 };
      enum { RESPONSE_ACCEPTED_TOO_LONG = 2 };
      enum { RESPONSE_ACCEPTED_TOO_SHORT = 3 };
      enum { RESPONSE_PARAM_ERROR = 4 };
      enum { RESPONSE_NOT_APPLICABLE_IN_CURRENT_STATE = 5 };
      enum { RESPONSE_DATA_NOT_AVAILABLE = 6 };
      enum { RESPONSE_MESSAGE_START_ERROR = 7 };
      enum { RESPONSE_MESSAGE_END_ERROR = 8 };
      enum { RESPONSE_BYTE_COUNT_ERROR = 9 };
      enum { RESPONSE_CHECKSUM_ERROR = 10 };
      enum { PARAMS_NO_CHANGE = 0 };
      enum { PARAMS_CHANGE = 1 };

    Ack():
      transaction(0),
      id(0),
      response_code(0),
      params_status(0),
      error_parameter_name()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->transaction >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transaction >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transaction);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->response_code >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->response_code >> (8 * 1)) & 0xFF;
      offset += sizeof(this->response_code);
      *(outbuffer + offset + 0) = (this->params_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->params_status);
      for( uint8_t i = 0; i < 32; i++){
      *(outbuffer + offset + 0) = (this->error_parameter_name[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error_parameter_name[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->transaction =  ((uint16_t) (*(inbuffer + offset)));
      this->transaction |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->transaction);
      this->id =  ((uint16_t) (*(inbuffer + offset)));
      this->id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->id);
      this->response_code =  ((uint16_t) (*(inbuffer + offset)));
      this->response_code |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->response_code);
      this->params_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->params_status);
      for( uint8_t i = 0; i < 32; i++){
      this->error_parameter_name[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error_parameter_name[i]);
      }
     return offset;
    }

    const char * getType(){ return "novatel_msgs/Ack"; };
    const char * getMD5(){ return "f84607dc6beaf1cb6772d23af7221bdf"; };

  };

}
#endif