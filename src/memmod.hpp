#pragma once

//OFFSETS
#define r_Drawothermodels 0xBC8870
#define fog_override 0xBF6850

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
  int wireframe = 1;
  int fog = 0;
  pid_t pid;
  unsigned long clientso;
  void setwireframe();//Address, PID, new value
  void setfogoverride();//Address, PID, new value
  pid_t getpid();
  u_int64_t getclient(pid_t);

};
 
