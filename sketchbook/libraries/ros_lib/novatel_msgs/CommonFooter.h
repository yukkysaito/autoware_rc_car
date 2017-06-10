#ifndef _ROS_novatel_msgs_CommonFooter_h
#define _ROS_novatel_msgs_CommonFooter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace novatel_msgs
{

  class CommonFooter : public ros::Msg
  {
    public:
      uint32_t checksum;

    CommonFooter():
      checksum(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->checksum >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->checksum >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->checksum >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->checksum >> (8 * 3)) & 0xFF;
      offset += sizeof(this->checksum);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->checksum =  ((uint32_t) (*(inbuffer + offset)));
      this->checksum |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->checksum |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->checksum |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->checksum);
     return offset;
    }

    const char * getType(){ return "novatel_msgs/CommonFooter"; };
    const char * getMD5(){ return "5a3857d7abd4ce1de381cc063c02bc83"; };

  };

}
#endif