#pragma once

//OFFSETS
#define r_Drawothermodels 0xBC7710
#define fog_override 0xBF56F0

#include <sys/ptrace.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
//#include <string.h>

class memMod
{
public:
  int wireframe = 1;
  int fog = 0;
  int pid;
  unsigned long clientso;
  //int getwireframe();
  //int getfogoverride();
  void* getvalue(unsigned int, int);//Address and PID
  void setwireframe();//Address, PID, new value
  void setfogoverride();//Address, PID, new value
  int getpid();
  char* getOut(std::string);
};
 
