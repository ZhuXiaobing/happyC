#include <assert.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static int sigs[] = {SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM};
static void (*rets[]) (int) = {SIG_DFL, SIG_ERR, SIG_IGN};
static sig_atomic_t atomic;

static void field_fpe(int sig) {
    assert(sig == SIGFPE);
    puts("SUCCESS testing<signal.h>");
    exit(EXIT_SUCCESS); // 一般来说，这行应该加上，但是如果不加，第一次调用raise的后续代码也不会执行。
}

int main() {
    printf("sizeof sig_atomic_t is %u\n", sizeof(sig_atomic_t));
    // 按照对于C标准库P202中对原理的代码介绍，对于某一个信号的处理函数只管用一次，之后又被设置为SIG_DFL。
    // 下一次使用又需要通过signal重新设置信号处理函数。
    assert(signal(SIGFPE, &field_fpe) == SIG_DFL);
    assert(signal(SIGFPE, &field_fpe) == &field_fpe);
    raise(SIGFPE);
    printf("the second raise"); // 不会执行。
    raise(SIGFPE);
    puts("FAILURE testing<signal.h>");
    exit(EXIT_FAILURE);
}