#pragma once

//OFFSETS
#define r_Drawothermodels 0xBC8870
#define fog_override 0xBF6850
//#define playerbase 0xb90744 //Offset from client.so
#define m_fflags 0x340 //Offset from playerbase
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
#include <X11/Xlib.h>
#include <X11/Intrinsic.h>
#include <X11/extensions/XTest.h>

class memMod{
public:
  u_int16_t flags;
  int wireframe = 1;
  int fog = 0;
  pid_t pid;
  unsigned long clientso;
  unsigned long pbase;
  void setwireframe(int);
  void setfogoverride(int);
  void kbsetwireframe();//To be used with kbdreader only
  void kbsetfogoverride();//To be used with kbdreader only
  pid_t getpid();
  u_int64_t getclient(pid_t);
  u_int32_t* getpbase();
  u_int8_t getflags();
  void bhop();
private:
  u_int32_t playerbase_offset = 0xb90744;
  u_int32_t clientbase;
  u_int32_t playerbase;
  u_int32_t pbaseloc;
  u_int32_t flagsloc;
  Display *dis = XOpenDisplay(NULL);
  KeyCode modcode = XKeysymToKeycode(dis, XStringToKeysym("l"));

};
 
