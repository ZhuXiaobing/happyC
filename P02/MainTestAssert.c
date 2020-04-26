#define NDEBUG    // 本翻译单元从这里开始assert宏不生效。
#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static int val = 0;

static void field_abort(int sig) {
    if (val == 1) {
        puts("success testing assert.h");
        exit(EXIT_SUCCESS);
    } else {
        puts("failure testing assert.h");
        exit(EXIT_FAILURE);
    }
}

static void dummy() {
    int i = 0;
    assert(i == 0);
    assert(i == 1);
}

#undef NDEBUG    // 本翻译单元从这里开始assert宏开始生效。 
#include <assert.h>

int main() {
    assert(signal(SIGABRT, &field_abort) != SIG_ERR);
    dummy();
    assert(val == 0);
    ++val;
    fputs("Sample assertion failure message\n", stderr);
    assert(val ==0);
    puts("failure TESTING assert.h");
    return(EXIT_FAILURE);
}