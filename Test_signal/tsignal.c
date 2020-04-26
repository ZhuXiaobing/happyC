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
    exit(EXIT_SUCCESS);
}

int main() {
    printf("sizeof sig_atomic_t is %u\n", sizeof(sig_atomic_t));
    assert(signal(SIGFPE, &field_fpe) == SIG_DFL); // 这一次调用会
    assert(signal(SIGFPE, &field_fpe) == &field_fpe);
    raise(SIGFPE);
    puts("FAILURE testing<signal.h>");
    exit(EXIT_FAILURE);
}