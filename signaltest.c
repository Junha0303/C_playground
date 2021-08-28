#define _GNU_SOURCE
#include <stdio.h>
#include <assert.h>
#include <signal.h>

static inline void myHandler(int iSig)
{
    printf("My Handler With Argument %d\n", iSig);
}

int main(int argc, char const *argv[])
{
    void (*pfRet)(int);
    pfRet = signal(SIGINT, myHandler);
    assert(pfRet != SIG_ERR);

    printf("Entering an infinite loop\n");
    for(;;)
        ;
    
    return 0;
}
