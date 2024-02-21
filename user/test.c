#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"

int main(int argc, char *argv[])
{   
    int n = 0;
    if (argc >= 2) n = atoi(argv[1]);
    
    printf("say hello to %d\n", n);
    hello(n);
    sched_statistics();
    exit(0);
}