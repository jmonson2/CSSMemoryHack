#include "kbdreader.hpp"
#include "memmod.hpp"

int main()
{
  kbdReader k;
  memMod m;
  int key;
  short key_active;
  m.getpid();
  std::cout << k.getdev() << std::endl;
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
      
    
  // std::cout << k.getCurrentKey() << std::endl;
  return 0;
  
}
