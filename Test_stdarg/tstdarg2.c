#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct {
    char c;
} Cstruct;

static int tryit (const char *fmt, ...) {
    int ctr = 0;
    va_list ap;
    va_start(ap, fmt);
    for (; *fmt; ++fmt) {
        switch (*fmt) {
        case 'i':
            printf("va_arg(ap,int)=%d\n", va_arg(ap, int));
            ctr ++;
            break;
        case 'd':
            printf("va_arg(ap,double)=%f\n", va_arg(ap, double));
            ctr ++;
            break;
        case 'p':
            printf("va_arg(ap, char*)=%s\n", va_arg(ap, char *));
            ctr ++;
            break;
        case 's':
            printf("va_arg(ap, Cstruct)=%d\n", va_arg(ap, Cstruct).c);
            ctr ++;
            break;
        default:
            break;
        }
    }
    va_end(ap);
    return ctr;
}

int main(void) {
    Cstruct x = {3};
    assert(tryit("iisdi", '\1', 2, x, 4.0, 5) == 5);
    assert(tryit("") == 0);
    assert(tryit("pdp", "\1hello", 2.0, "\3world") == 3);
    printf("sizeof(va_list) == %d\n", sizeof(va_list));
    puts("SUCCESS TEST <stdarg.h>");
    return 0;
}
