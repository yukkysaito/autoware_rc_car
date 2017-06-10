#ifndef _ROS_grid_map_msgs_GridMap_h
#define _ROS_grid_map_msgs_GridMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "grid_map_msgs/GridMapInfo.h"
#include "std_msgs/Float32MultiArray.h"

namespace grid_map_msgs
{

  class GridMap : public ros::Msg
  {
    public:
      grid_map_msgs::GridMapInfo info;
      uint8_t layers_length;
      char* st_layers;
      char* * layers;
      uint8_t basic_layers_length;
      char* st_basic_layers;
      char* * basic_layers;
      uint8_t data_length;
      std_msgs::Float32MultiArray st_data;
      std_msgs::Float32MultiArray * data;
      uint16_t outer_start_index;
      uint16_t inner_start_index;

    GridMap():
      info(),
      layers_length(0), layers(NULL),
      basic_layers_length(0), basic_layers(NULL),
      data_length(0), data(NULL),
      outer_start_index(0),
      inner_start_index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->info.serialize(outbuffer + offset);
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
      *(outbuffer + offset++) = basic_layers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < basic_layers_length; i++){
      uint32_t length_basic_layersi = strlen(this->basic_layers[i]);
      memcpy(outbuffer + offset, &length_basic_layersi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->basic_layers[i], length_basic_layersi);
      offset += length_basic_layersi;
      }
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->outer_start_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->outer_start_index >> (8 * 1)) & 0xFF;
      offset += sizeof(this->outer_start_index);
      *(outbuffer + offset + 0) = (this->inner_start_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->inner_start_index >> (8 * 1)) & 0xFF;
      offset += sizeof(this->inner_start_index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->info.deserialize(inbuffer + offset);
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
      uint8_t basic_layers_lengthT = *(inbuffer + offset++);
      if(basic_layers_lengthT > basic_layers_length)
        this->basic_layers = (char**)realloc(this->basic_layers, basic_layers_lengthT * sizeof(char*));
      offset += 3;
      basic_layers_length = basic_layers_lengthT;
      for( uint8_t i = 0; i < basic_layers_length; i++){
      uint32_t length_st_basic_layers;
      memcpy(&length_st_basic_layers, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_basic_layers; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_basic_layers-1]=0;
      this->st_basic_layers = (char *)(inbuffer + offset-1);
      offset += length_st_basic_layers;
        memcpy( &(this->basic_layers[i]), &(this->st_basic_layers), sizeof(char*));
      }
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (std_msgs::Float32MultiArray*)realloc(this->data, data_lengthT * sizeof(std_msgs::Float32MultiArray));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(std_msgs::Float32MultiArray));
      }
      this->outer_start_index =  ((uint16_t) (*(inbuffer + offset)));
      this->outer_start_index |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->outer_start_index);
      this->inner_start_index =  ((uint16_t) (*(inbuffer + offset)));
      this->inner_start_index |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->inner_start_index);
     return offset;
    }

    const char * getType(){ return "grid_map_msgs/GridMap"; };
    const char * getMD5(){ return "95681e052b1f73bf87b7eb984382b401"; };

  };

}
#endif