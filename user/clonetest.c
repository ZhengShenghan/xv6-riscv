// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define N  3

void
print(const char *s)
{
  write(1, s, strlen(s));
}

int
main(void)
{
  int n = 0, pid;

  print("clone test\n");

  for(n=0; n<N; n++){
    void *m = malloc(1<<20);
    pid = clone(m+(1 << 20)-1);
    printf("clone %d: %d\n", n, pid);
    if (pid == 0) {
      for (int i = 0; i < 1000000000; i++);
      return 0;
    }
  }

//  for(;;);
  for(n=0; n<N; n++){
    pid = wait(0);
    printf("%d exited\n", pid);
  }
  if ((pid = wait(0)) != -1) {
    printf("bad wait: more children %d\n", pid);
  }

  print("clone test OK\n");
  return 0;
}
