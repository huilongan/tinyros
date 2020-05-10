/*
 * File      : node_handle_base.h
 * This file is part of tiny_ros
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-04-24     Pinkie.Fu    initial version
 */
#ifndef TINYROS_NODE_HANDLE_BASE_H_
#define TINYROS_NODE_HANDLE_BASE_H_
#include <stdint.h>
#include <rtthread.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros {

#define TINYROS_LOG_TOPIC "tinyros_log_11315"

const int THREAD_MAIN_LOOP_PRIORITY   = 1;
const int THREAD_MAIN_LOOP_TICK       = 40;
const int THREAD_MAIN_LOOP_STACK_SIZE = 4096; // bytes

const int THREAD_LOG_KEEPALIVE_PRIORITY   = 20;
const int THREAD_LOG_KEEPALIVE_TICK       = 10;
const int THREAD_LOG_KEEPALIVE_STACK_SIZE = 1024; // bytes

const int THREAD_NEGOTIATE_KEEPALIVE_PRIORITY   = 20;
const int THREAD_NEGOTIATE_KEEPALIVE_TICK       = 10;
const int THREAD_NEGOTIATE_KEEPALIVE_STACK_SIZE = 1024; // bytes

const int MAX_SUBSCRIBERS = 20;
const int MAX_PUBLISHERS = 20;
const int INPUT_SIZE = 200; // bytes
const int OUTPUT_SIZE = 200; // bytes

const uint8_t MODE_FIRST_FF       = 0;
const uint8_t MODE_PROTOCOL_VER   = 1;
const uint8_t PROTOCOL_VER        = 0xb9;
const uint8_t MODE_SIZE_L         = 2;
const uint8_t MODE_SIZE_L1        = 3;
const uint8_t MODE_SIZE_H         = 4;
const uint8_t MODE_SIZE_H1        = 5;
const uint8_t MODE_SIZE_CHECKSUM  = 6;
const uint8_t MODE_TOPIC_L        = 7;
const uint8_t MODE_TOPIC_L1       = 8;
const uint8_t MODE_TOPIC_H        = 9;
const uint8_t MODE_TOPIC_H1       = 10;
const uint8_t MODE_MESSAGE        = 11;
const uint8_t MODE_MSG_CHECKSUM   = 12;

const int SPIN_OK = 0;
const int SPIN_ERR = -1;

class NodeHandleBase_
{
public:
  struct rt_mutex mutex_;
  struct rt_mutex srv_id_mutex_;
  struct rt_mutex main_loop_mutex_;
  bool main_loop_init_;

  NodeHandleBase_() {
    main_loop_init_ = false;
  }

  ~NodeHandleBase_() {
  }

  virtual bool initNode(tinyros::string portName) { return false; }
  virtual int publish(uint32_t id, const Msg* msg, bool islog = false) { return -1; }
  virtual int spin() { return -1; }
  virtual void exit() {}
  virtual bool ok() { return false; }
  virtual void logdebug(const char* msg) {}
  virtual void loginfo(const char* msg) {}
  virtual void logwarn(const char* msg) {}
  virtual void logerror(const char* msg) {}
  virtual void logfatal(const char* msg) {}
};
}

#endif /* TINYROS_NODE_HANDLE_BASE_H_ */
