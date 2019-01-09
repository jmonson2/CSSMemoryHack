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
void memMod::kbsetwireframe(){
  struct iovec local[1];
  struct iovec remote[1];
  local[0].iov_base = &wireframe;
  local[0].iov_len = sizeof(int);
  remote[0].iov_base = (void*)(r_Drawothermodels+clientso);
  remote[0].iov_len = sizeof(int);
  process_vm_readv(pid,local,1,remote,1,0);
  if (wireframe == 1){
      wireframe = 2;
      std::cout << "Wireframe on\n";
    }
  else if (wireframe == 2){
      wireframe = 1;
      std::cout << "Wireframe off\n";
    }

  process_vm_writev(pid,local,1,remote,1,0);

}

void memMod::kbsetfogoverride(){
  struct iovec local[1];
  struct iovec remote[1];
  local[0].iov_base = &fog;
  local[0].iov_len = sizeof(int);
  remote[0].iov_base = (void*)(fog_override+clientso);
  remote[0].iov_len = sizeof(int);
  process_vm_readv(pid,local,1,remote,1,0);
  if (fog == 1){
      fog = 0;
      std::cout << "Fog on\n";
    }
  else if (fog == 0){
      fog = 1;
      std::cout << "Fog off\n";
    }
  process_vm_writev(pid,local,1,remote,1,0);

}


pid_t memMod::getpid(){
  char line[10];
  FILE* cmd = popen("pidof -s hl2_linux", "r");
  fgets(line, 10, cmd);
  pid = strtol(line, NULL, 10);

  pclose(cmd);
  clientso = memMod::getclient(pid);
  return pid;
}

u_int64_t memMod::getclient(pid_t pid){
  char line[16];
  std::string s = "grep client.so -m2 /proc/" + std::to_string(pid) + "/maps | cut -c 1-8 | head -n1";
  FILE* cmd = popen(s.c_str(), "r");
  fgets(line,16,cmd);
  clientbase = strtol(line, NULL, 16);
  return clientbase;
}
u_int32_t* memMod::getpbase(){
  pbaseloc = clientbase+playerbase_offset;
  struct iovec local[1];
  struct iovec remote[1];
  local[0].iov_base = &playerbase;
  local[0].iov_len = sizeof(u_int32_t);
  remote[0].iov_base = (void*)pbaseloc;
  remote[0].iov_len = sizeof(u_int32_t);
  process_vm_readv(pid,local,1,remote,1,0);
  return &playerbase;
}

u_int8_t memMod::getflags(){
  flagsloc = playerbase+m_fflags;
  struct iovec local[1];
  struct iovec remote[1];
  local[0].iov_base = &flags;
  local[0].iov_len = sizeof(u_int32_t);
  remote[0].iov_base = (void*)flagsloc;
  remote[0].iov_len = sizeof(u_int32_t);
  process_vm_readv(pid,local,1,remote,1,0);
  bhop();
  return flags;
}
void memMod::bhop(){
  
  if(flags == 257){
    XTestFakeKeyEvent(dis, modcode, True, 0);
    XFlush(dis);
    XTestFakeKeyEvent(dis, modcode, False, 0);
    XFlush(dis);
  }
}



  


  

  

      
