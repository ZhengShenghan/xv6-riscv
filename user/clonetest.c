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

void
clonetest(void)
{
  int n, pid;

  print("clone test\n");

  for(n=0; n<N; n++){
    void *m = malloc(1<<20);
    pid = clone((void*)((uint64)m / 4096 * 4096 + 4096));
    printf("clone %d: %d\n", n, pid);
    if (pid == 0) return;
  }

  for(; n > 0; n--){
    if(wait(0) < 0){
      print("wait stopped early\n");
      exit(1);
    }
  }

  if(wait(0) != -1){
    print("wait got too many\n");
    exit(1);
  }

  print("clone test OK\n");
}

int
main(void)
{
  clonetest();
  exit(0);
}
