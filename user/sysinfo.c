#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"

int main(int argc, char* argv[])
{
  printf("sysinfo(2)=%d\n",sysinfo(2));

  exit(0);
}