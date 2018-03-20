#pragma once

#include <linux/input.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
//class kbdReader
//{
//public:
// kbdReader();j
// kbdReader(char*);
static const char *const evval[3] =
  {
    "RELEASED",
    "PRESSED",
    "REPEATED"
  };
class kbdReader
{
public:
  kbdReader();
  kbdReader(char*);
  int getCurrentKey();
  int getKeyStatus();
  int Init();
  const char* getdev();
private:
  ssize_t n;
  int fd;
  struct input_event ev;
  const char* dev;

  
};
//};
