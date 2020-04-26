#include <assert.h>
#include <setjmp.h>
#include <stdio.h>

static int ctr;
static jmp_buf b0;

static void jmpto(int n) {
    longjmp(b0, n);
}

static char *stackptr(void) {
    char ch;
    return  &ch;
}

static int tryit(void) {
    jmp_buf b1;
    char *sp = stackptr();

    ctr = 0;
    switch(setjmp(b0)) {
        case 0:
            assert(sp == stackptr());
            assert(ctr == 0);
            ++ ctr;
            jmpto(1);
            break;
        case 1:
            assert(sp == stackptr());
            assert(ctr == 1);
            ++ ctr;
            jmpto(2);
            break;
        case 2:
            switch(setjmp(b1)) {
                case 0:
                    assert(sp == stackptr());
                    ++ ctr;
                    assert(ctr == 3);
                    longjmp(b1, -10);
                    break;
                case -10:
                    assert(sp == stackptr());
                    ++ ctr;
                    assert(ctr == 4);
                    jmpto(3);
                    break;
                case 5:
                    return 100;

            }       
        case 3:
            longjmp(b1, 5);
            break; 
    }
    return -1;
}

int main(void) {
    assert(tryit() == 100);
    printf("sizeof(jmp_buf) == %u\n", sizeof(jmp_buf));
    puts("SUCCESS testing<setjmp.h>\n");
    return 0;
}
