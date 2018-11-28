#include "../Headers/kbdreader.hpp"
#include "../Headers/memmod.hpp"


int main(int argc, char** argv)
{
  pid_t pid;
  kbdReader k;
  memMod m;
  int key;
  short key_active;
  pid = m.getpid();
  m.pbase = m.getpbase();
  k.Init();
  
  while (1)
  {
    key = k.getCurrentKey();
    if (key == 64 && k.getKeyStatus() == 1) // 64=F6
	  {
	    m.setwireframe();
	  }
    if (key == 65 && k.getKeyStatus() == 1) // 65=F7
	  {
	    m.setfogoverride();
	  }
  }
      
  return 0;
  
}
