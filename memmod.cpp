#include "memmod.hpp"
//This is for ptrace PEEKDATA.
void getValue(unsigned int address, int pid)
{
  
}
//To retrieve local, safer data
void memMod::setwireframe()
{
  if (wireframe == 1)
    {
      wireframe = 2;
      std::cout << "Wireframe toggled on!\n";
    }
  else if (wireframe == 2)
    {
      wireframe = 1;
      std::cout << "Wireframe toggled off!\n";
    }
  ptrace(PTRACE_ATTACH, pid);
  wait(0);//CRITICAL STEP, else fails to attach and detach properly!
  ptrace(PTRACE_POKEDATA, pid, r_Drawothermodels + clientso, wireframe);
  ptrace(PTRACE_DETACH, pid);
}

void memMod::setfogoverride()
{
  if (fog == 1)
    {
      fog = 0;
      std::cout << "Fog toggled on!\n";
    }
  else if (fog == 0)
    {
      fog = 1;
      std::cout << "Fog toggled off!\n";
    }
  ptrace(PTRACE_ATTACH, pid);
  wait(0);//CRITICAL STEP, else fails to attach and detach properly!
  ptrace(PTRACE_POKEDATA, pid, fog_override + clientso, fog);
  ptrace(PTRACE_DETACH, pid);
}


 
  


char* memMod::getOut(std::string s)
{
  char *clientso = (char*) malloc(sizeof(char)*10);
  FILE *fp = popen(s.c_str(), "r");

  while (fgets(clientso, 10, fp))
    puts (clientso);
  pclose(fp);
  return clientso;

}
int memMod::getpid()
{
  FILE *fp = popen("pidof hl2_linux", "r");
  char s_pid[10];
  char* s_clientso = (char*) malloc(sizeof(char)*10);
  std::string s_command;
  //int pid;
  unsigned short s_pidC = 0;
  int exit = 0;

  
  if (popen == NULL)
    {
      std::cout << "START CSS!\n";
      return 1;
    }
  while (std::fgets(s_pid, 10, fp))
    {
      puts (s_pid);
    }
  pclose(fp);

  for (int i = 0; s_pid[i] != NULL; i++)
    s_pidC++;

  pid = std::atoi(s_pid);

  s_command = "cat /proc//maps | grep 'client.so' -m2 | cut -c 1-8 | head -n1";
  s_command.insert(10, s_pid, s_pidC-1);

  
  s_clientso = getOut(s_command);
  clientso = atoi(s_clientso);
  std::string a = getOut(s_command);
  system("clear");
  clientso = std::stol (a,NULL,16);
  std::cout << std::hex << clientso << std::endl;
  std::cout << s_pid << std::endl;
  return pid;
}

  


  

  

  
