#include "kernel/types.h"
#include "user/user.h"

struct lock_t {
  uint locked;
}; 

int thread_create(void *(start_routine)(void*), void *arg);
void lock_init(struct lock_t* lock);
void lock_acquire(struct lock_t* lock);
void lock_release(struct lock_t* lock);
