#include "../Headers/kbdreader.hpp"
#define dev "/dev/input/by-id/usb-_Varmilo-event-kbd"
kbdReader::kbdReader()
  {
    
    static const char *const evval[3] =
    {
      "RELEASED",
	    "PRESSED",
	    "REPEATED"
      };
    
    
    struct input_event ev;
    ssize_t n;
    int fd;
  }

/*
*/
const char* kbdReader::getdev()
{
  return dev;
}

int kbdReader::getKeyStatus()
{
  return ev.value;
}
int kbdReader::getCurrentKey()
{
  kbdReader::n = read(fd, &ev, sizeof ev);
  if (n == (ssize_t)-1)
    {
      if (errno == EINTR);
      else
	return -1;
    }
  else if (n != sizeof ev)
    {
      errno = EIO;
      return -1;
    }
  return (int)ev.code;
}


int kbdReader::Init()
{
  fd = open(dev, O_RDONLY);
  if (fd == -1)
  {
	  fprintf(stderr, "Cannot open %s: %s. Change dev var in /dev/input/by-id/ and recompile!\n", dev, strerror (errno));
  }
  return fd;
}
    
  
  
  
