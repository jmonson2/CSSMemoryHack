#pragma once

//OFFSETS
#define r_Drawothermodels 0xBC8870
#define fog_override 0xBF6850
#define m_fflags 0x2182411C
#define m_iHealth 0x218240f8

#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <sys/uio.h>

class memMod
{
public:
  u_int16_t flags;
  int wireframe = 1;
  int fog = 0;
  pid_t pid;
  unsigned long clientso;
  unsigned long pbase;
  void setwireframe();//Address, PID, new value
  void setfogoverride();//Address, PID, new value
  pid_t getpid();
  u_int64_t getclient(pid_t);
  u_int64_t getpbase();
  u_int8_t getflags();
  

};
 