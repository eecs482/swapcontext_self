#include <ucontext.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
    int first = 1;

    ucontext_t ctx, ctx_2;
    ucontext_t *from, *to;
    from = &ctx;
#ifdef SWAP_SAME_CONTEXT
    to = &ctx; (void)ctx_2;
#else
    to = &ctx_2;
#endif

    getcontext(to);
    if (first) {
        printf("(1) Got intial context\n");
        first = 0;
    } else {
        printf("(3) going back to saved context\n");
        setcontext(from);
    }

    printf("(2) about to swap to initial context\n");
    if (swapcontext(from, to) < 0) {
        printf("swapcontext failed: %s\n", strerror(errno));
    }
    printf("(4) back at saved context\n");
    return 0;
}
