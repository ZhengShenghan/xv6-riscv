#include "kernel/types.h"
#include "kernel/riscv.h"
#include "user/thread.h"

int thread_create(void *(start_routinue)(void*), void *arg){
  void *stack = malloc(PGSIZE);
  if(!stack) return -1;
  int pid = clone(stack);
  if (pid == 0) {
    start_routinue(arg);
    exit(0);
  } else
    return 0;
}

void lock_init(struct lock_t *lock){
  lock->locked = 0;
}

void lock_acquire(struct lock_t *lock){
  while(__sync_lock_test_and_set(&lock->locked, 1)) {}
  __sync_synchronize();
  return;
}

void lock_release(struct lock_t *lock){
  __sync_synchronize();
  __sync_lock_release(&lock->locked);
}