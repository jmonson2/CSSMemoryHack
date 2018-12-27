#include "../Headers/memmod.hpp"
void memMod::setwireframe(int newval){
  struct iovec local[1];
  struct iovec remote[1];
  local[0].iov_base = &newval;
  local[0].iov_len = sizeof(int);
  remote[0].iov_base = (void*)(r_Drawothermodels+clientso);
  remote[0].iov_len = sizeof(int);

  process_vm_writev(pid,local,1,remote,1,0);
}
void memMod::setfogoverride(int newval){
  struct iovec local[1];
  struct iovec remote[1];
  local[0].iov_base = &newval;
  local[0].iov_len = sizeof(int);
  remote[0].iov_base = (void*)(fog_override+clientso);
  remote[0].iov_len = sizeof(int);

  process_vm_writev(pid,local,1,remote,1,0);
}
void memMod::kbsetwireframe()
{
  struct iovec local[1];
  struct iovec remote[1];
  local[0].iov_base = &wireframe;
  local[0].iov_len = sizeof(int);
  remote[0].iov_base = (void*)(r_Drawothermodels+clientso);
  remote[0].iov_len = sizeof(int);
  process_vm_readv(pid,local,1,remote,1,0);
  if (wireframe == 1)
    {
      wireframe = 2;
      std::cout << "Wireframe on\n";
    }
  else if (wireframe == 2)
    {
      wireframe = 1;
      std::cout << "Wireframe off\n";
    }

  process_vm_writev(pid,local,1,remote,1,0);

}

void memMod::kbsetfogoverride()
{
  struct iovec local[1];
  struct iovec remote[1];
  local[0].iov_base = &fog;
  local[0].iov_len = sizeof(int);
  remote[0].iov_base = (void*)(fog_override+clientso);
  remote[0].iov_len = sizeof(int);
  process_vm_readv(pid,local,1,remote,1,0);
  if (fog == 1)
    {
      fog = 0;
      std::cout << "Fog on\n";
    }
  else if (fog == 0)
    {
      fog = 1;
      std::cout << "Fog off\n";
    }
  process_vm_writev(pid,local,1,remote,1,0);

}


pid_t memMod::getpid()
{
  char line[10];
  FILE* cmd = popen("pidof -s hl2_linux", "r");
  fgets(line, 10, cmd);
  pid = strtol(line, NULL, 10);

  pclose(cmd);
  clientso = memMod::getclient(pid);
  return pid;
}

u_int64_t memMod::getclient(pid_t pid)
{
  u_int64_t base = -1;
  char line[16];
  std::string s = "grep client.so -m2 /proc/" + std::to_string(pid) + "/maps | cut -c 1-8 | head -n1";
  FILE* cmd = popen(s.c_str(), "r");
  fgets(line,16,cmd);
  base = strtol(line, NULL, 16);
  return base;
}
u_int64_t memMod::getpbase()
{
  u_int64_t base = -1;
  char line[16];
  std::string s = "sed -n 8p /proc/"+std::to_string(pid) + "/maps |cut -c 1-8";
  FILE* cmd = popen(s.c_str(), "r");
  fgets(line,16,cmd);
  base = strtol(line, NULL, 16);
  return base;
  
}

u_int8_t memMod::getflags()
{
  struct iovec local[1];
  struct iovec remote[1];
  local[0].iov_base = &flags;
  local[0].iov_len = sizeof(u_int16_t);
  remote[0].iov_base = (void*)(m_fflags+pbase);
  remote[0].iov_len = sizeof(u_int16_t);
  process_vm_readv(pid,local,1,remote,1,0);
  std::cout << flags << std::endl;
  return flags;
}


  


  

  

  
