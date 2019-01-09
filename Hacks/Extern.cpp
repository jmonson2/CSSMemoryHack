#include "../Headers/kbdreader.hpp"
#include "../Headers/memmod.hpp"
#include "../Headers/input.hpp"

int main(int argc, char** argv)
{
  pid_t pid;
  input in;
  kbdReader k;
  memMod m;
  int key;
  short key_active;
  pid = m.getpid();
  m.getpbase();
  k.Init();
  //in.select(m);
  while (1)
  {
    key = k.getCurrentKey();
    if (key == 64 && k.getKeyStatus() == 1) // 64=F6
	  {
	    m.kbsetwireframe();
	  }
    if (key == 65 && k.getKeyStatus() == 1) // 65=F7
	  {
	    m.kbsetfogoverride();
	  }
  }
  return 0;
  
}
