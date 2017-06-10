#ifndef _ROS_novatel_msgs_BESTPOS_h
#define _ROS_novatel_msgs_BESTPOS_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "novatel_msgs/CommonHeader.h"

namespace novatel_msgs
{

  class BESTPOS : public ros::Msg
  {
    public:
      novatel_msgs::CommonHeader header;
      uint32_t solution_status;
      uint32_t position_type;
      float latitude;
      float longitude;
      float altitude;
      float undulation;
      uint32_t datum_id;
      float latitude_std;
      float longitude_std;
      float altitude_std;
      uint8_t stn_id[4];
      float diff_age;
      float sol_age;
      uint8_t svs;
      uint8_t sol_svs;
      uint8_t l1_svs;
      uint8_t mult_svs;
      uint8_t reserved;
      uint8_t extsolstat;
      uint8_t gal_sig_mask;
      uint8_t sig_mask;
      enum { SOLUTION_STATUS_SOLUTION_COMPUTED = 0 };
      enum { SOLUTION_STATUS_INSUFFICIENT_OBSERVATIONS = 1 };
      enum { SOLUTION_STATUS_NO_CONVERGENCE = 2 };
      enum { SOLUTION_STATUS_SINGULARITY_AT_PARAMETERS_MATRIX = 3 };
      enum { SOLUTION_STATUS_COVARIANCE_TRACE_EXCEEDS_MAXIMUM = 4 };
      enum { SOLUTION_STATUS_TEST_DISTANCE_EXCEEDED = 5 };
      enum { SOLUTION_STATUS_COLD_START = 6 };
      enum { SOLUTION_STATUS_VELOCITY_OR_HEIGHT_LIMIT_EXCEEDED = 7 };
      enum { SOLUTION_STATUS_VARIANCE_EXCEEDS_LIMITS = 8 };
      enum { SOLUTION_STATUS_RESIDUALS_TOO_LARGE = 9 };
      enum { SOLUTION_STATUS_INTEGRITY_WARNING = 13 };
      enum { SOLUTION_STATUS_PENDING = 18 };
      enum { SOLUTION_STATUS_INVALID_FIX = 19 };
      enum { SOLUTION_STATUS_INVALID_RATE = 22 };
      enum { POSITION_TYPE_NONE = 0 };
      enum { POSITION_TYPE_FIXED = 1 };
      enum { POSITION_TYPE_FIXEDHEIGHT = 2 };
      enum { POSITION_TYPE_FLOATCONV = 4 };
      enum { POSITION_TYPE_WIDELANE = 5 };
      enum { POSITION_TYPE_NARROWLANE = 6 };
      enum { POSITION_TYPE_DOPPLER_VELOCITY = 8 };
      enum { POSITION_TYPE_SINGLE = 16 };
      enum { POSITION_TYPE_PSRDIFF = 17 };
      enum { POSITION_TYPE_WAAS = 18 };
      enum { POSITION_TYPE_PROPAGATED = 19 };
      enum { POSITION_TYPE_OMNISTAR = 20 };
      enum { POSITION_TYPE_L1_FLOAT = 32 };
      enum { POSITION_TYPE_IONOFREE_FLOAT = 33 };
      enum { POSITION_TYPE_NARROW_FLOAT = 34 };
      enum { POSITION_TYPE_L1_INT = 48 };
      enum { POSITION_TYPE_WIDE_INT = 49 };
      enum { POSITION_TYPE_NARROW_INT = 50 };
      enum { POSITION_TYPE_RTK_DIRECT_INS = 51 };
      enum { POSITION_TYPE_INS_SBAS = 52 };
      enum { POSITION_TYPE_INS_PSRSP = 53 };
      enum { POSITION_TYPE_INS_PSRDIFF = 54 };
      enum { POSITION_TYPE_INS_RTKFLOAT = 55 };
      enum { POSITION_TYPE_INS_RTKFIXED = 56 };
      enum { POSITION_TYPE_INS_OMNISTAR = 57 };
      enum { POSITION_TYPE_INS_OMNISTAR_HP = 58 };
      enum { POSITION_TYPE_INS_OMNISTAR_XP = 59 };
      enum { POSITION_TYPE_OMNISTAR_HP = 64 };
      enum { POSITION_TYPE_OMNISTAR_XP = 65 };
      enum { POSITION_TYPE_PPP_CONVERGING = 68 };
      enum { POSITION_TYPE_PPP = 69 };
      enum { POSITION_TYPE_INS_PPP_CONVERGING = 73 };
      enum { POSITION_TYPE_INS_PPP = 74 };

    BESTPOS():
      header(),
      solution_status(0),
      position_type(0),
      latitude(0),
      longitude(0),
      altitude(0),
      undulation(0),
      datum_id(0),
      latitude_std(0),
      longitude_std(0),
      altitude_std(0),
      stn_id(),
      diff_age(0),
      sol_age(0),
      svs(0),
      sol_svs(0),
      l1_svs(0),
      mult_svs(0),
      reserved(0),
      extsolstat(0),
      gal_sig_mask(0),
      sig_mask(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->solution_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->solution_status >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->solution_status >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->solution_status >> (8 * 3)) & 0xFF;
      offset += sizeof(this->solution_status);
      *(outbuffer + offset + 0) = (this->position_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_type);
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->altitude);
      union {
        float real;
        uint32_t base;
      } u_undulation;
      u_undulation.real = this->undulation;
      *(outbuffer + offset + 0) = (u_undulation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_undulation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_undulation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_undulation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->undulation);
      *(outbuffer + offset + 0) = (this->datum_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->datum_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->datum_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->datum_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->datum_id);
      union {
        float real;
        uint32_t base;
      } u_latitude_std;
      u_latitude_std.real = this->latitude_std;
      *(outbuffer + offset + 0) = (u_latitude_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude_std);
      union {
        float real;
        uint32_t base;
      } u_longitude_std;
      u_longitude_std.real = this->longitude_std;
      *(outbuffer + offset + 0) = (u_longitude_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude_std);
      union {
        float real;
        uint32_t base;
      } u_altitude_std;
      u_altitude_std.real = this->altitude_std;
      *(outbuffer + offset + 0) = (u_altitude_std.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude_std.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude_std.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude_std.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude_std);
      for( uint8_t i = 0; i < 4; i++){
      *(outbuffer + offset + 0) = (this->stn_id[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stn_id[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_diff_age;
      u_diff_age.real = this->diff_age;
      *(outbuffer + offset + 0) = (u_diff_age.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_diff_age.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_diff_age.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_diff_age.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->diff_age);
      union {
        float real;
        uint32_t base;
      } u_sol_age;
      u_sol_age.real = this->sol_age;
      *(outbuffer + offset + 0) = (u_sol_age.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sol_age.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sol_age.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sol_age.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sol_age);
      *(outbuffer + offset + 0) = (this->svs >> (8 * 0)) & 0xFF;
      offset += sizeof(this->svs);
      *(outbuffer + offset + 0) = (this->sol_svs >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sol_svs);
      *(outbuffer + offset + 0) = (this->l1_svs >> (8 * 0)) & 0xFF;
      offset += sizeof(this->l1_svs);
      *(outbuffer + offset + 0) = (this->mult_svs >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mult_svs);
      *(outbuffer + offset + 0) = (this->reserved >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reserved);
      *(outbuffer + offset + 0) = (this->extsolstat >> (8 * 0)) & 0xFF;
      offset += sizeof(this->extsolstat);
      *(outbuffer + offset + 0) = (this->gal_sig_mask >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gal_sig_mask);
      *(outbuffer + offset + 0) = (this->sig_mask >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sig_mask);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->solution_status =  ((uint32_t) (*(inbuffer + offset)));
      this->solution_status |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->solution_status |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->solution_status |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->solution_status);
      this->position_type =  ((uint32_t) (*(inbuffer + offset)));
      this->position_type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->position_type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->position_type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->position_type);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->altitude));
      union {
        float real;
        uint32_t base;
      } u_undulation;
      u_undulation.base = 0;
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_undulation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->undulation = u_undulation.real;
      offset += sizeof(this->undulation);
      this->datum_id =  ((uint32_t) (*(inbuffer + offset)));
      this->datum_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->datum_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->datum_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->datum_id);
      union {
        float real;
        uint32_t base;
      } u_latitude_std;
      u_latitude_std.base = 0;
      u_latitude_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude_std = u_latitude_std.real;
      offset += sizeof(this->latitude_std);
      union {
        float real;
        uint32_t base;
      } u_longitude_std;
      u_longitude_std.base = 0;
      u_longitude_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude_std = u_longitude_std.real;
      offset += sizeof(this->longitude_std);
      union {
        float real;
        uint32_t base;
      } u_altitude_std;
      u_altitude_std.base = 0;
      u_altitude_std.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude_std.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude_std.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude_std.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude_std = u_altitude_std.real;
      offset += sizeof(this->altitude_std);
      for( uint8_t i = 0; i < 4; i++){
      this->stn_id[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->stn_id[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_diff_age;
      u_diff_age.base = 0;
      u_diff_age.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_diff_age.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_diff_age.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_diff_age.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->diff_age = u_diff_age.real;
      offset += sizeof(this->diff_age);
      union {
        float real;
        uint32_t base;
      } u_sol_age;
      u_sol_age.base = 0;
      u_sol_age.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sol_age.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sol_age.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sol_age.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sol_age = u_sol_age.real;
      offset += sizeof(this->sol_age);
      this->svs =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->svs);
      this->sol_svs =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sol_svs);
      this->l1_svs =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->l1_svs);
      this->mult_svs =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mult_svs);
      this->reserved =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reserved);
      this->extsolstat =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->extsolstat);
      this->gal_sig_mask =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gal_sig_mask);
      this->sig_mask =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sig_mask);
     return offset;
    }

    const char * getType(){ return "novatel_msgs/BESTPOS"; };
    const char * getMD5(){ return "8321b9523105411643891c8653878967"; };

  };

}
#endif