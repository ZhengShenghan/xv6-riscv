#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"

int main(int argc, char* argv[])
{
    int info;
    int result;
    if (argc >= 2) printf("Wrong argument");

    // Convert the argument to an integer
  info = atoi(argv[1]);

  result = systeminfo(info);

  if (result == -1) {
    printf(2, "systeminfo syscall failed\n");
  } else {
    // Print the result based on the type of information requested
    switch (info) {
      case 0:
        printf(1, "Number of active processes: %d\n", result);
        break;
      case 1:
        printf(1, "Number of syscalls made so far: %d\n", result);
        break;
      case 2:
        printf(1, "Number of free memory pages: %d\n", result);
        break;
      default:
        printf(2, "Invalid information type\n");
        break;
    }
  }

  exit(0);
}