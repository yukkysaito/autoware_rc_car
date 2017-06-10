#ifndef _ROS_SERVICE_GetGridMap_h
#define _ROS_SERVICE_GetGridMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "grid_map_msgs/GridMap.h"

namespace grid_map_msgs
{

static const char GETGRIDMAP[] = "grid_map_msgs/GetGridMap";

  class GetGridMapRequest : public ros::Msg
  {
    public:
      const char* frame_id;
      float position_x;
      float position_y;
      float length_x;
      float length_y;
      uint8_t layers_length;
      char* st_layers;
      char* * layers;

    GetGridMapRequest():
      frame_id(""),
      position_x(0),
      position_y(0),
      length_x(0),
      length_y(0),
      layers_length(0), layers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_frame_id = strlen(this->frame_id);
      memcpy(outbuffer + offset, &length_frame_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      offset += serializeAvrFloat64(outbuffer + offset, this->position_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->position_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->length_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->length_y);
      *(outbuffer + offset++) = layers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < layers_length; i++){
      uint32_t length_layersi = strlen(this->layers[i]);
      memcpy(outbuffer + offset, &length_layersi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->layers[i], length_layersi);
      offset += length_layersi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_frame_id;
      memcpy(&length_frame_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length_y));
      uint8_t layers_lengthT = *(inbuffer + offset++);
      if(layers_lengthT > layers_length)
        this->layers = (char**)realloc(this->layers, layers_lengthT * sizeof(char*));
      offset += 3;
      layers_length = layers_lengthT;
      for( uint8_t i = 0; i < layers_length; i++){
      uint32_t length_st_layers;
      memcpy(&length_st_layers, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_layers; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_layers-1]=0;
      this->st_layers = (char *)(inbuffer + offset-1);
      offset += length_st_layers;
        memcpy( &(this->layers[i]), &(this->st_layers), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETGRIDMAP; };
    const char * getMD5(){ return "b6b21ecd617fdfa7f32e8c349cec3c2e"; };

  };

  class GetGridMapResponse : public ros::Msg
  {
    public:
      grid_map_msgs::GridMap map;

    GetGridMapResponse():
      map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETGRIDMAP; };
    const char * getMD5(){ return "4f8e24cfd42bc1470fe765b7516ff7e5"; };

  };

  class GetGridMap {
    public:
    typedef GetGridMapRequest Request;
    typedef GetGridMapResponse Response;
  };

}
#endif
