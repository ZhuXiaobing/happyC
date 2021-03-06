#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>

typedef struct {
    char f1;
    struct 
    {
        float flt;
    } f2;
    int f3;
} Str;

static char *pc = NULL;
static double *pd = NULL;
static size_t offs[] = {
    offsetof(Str, f1),
    offsetof(Str, f2),
    offsetof(Str, f3)
};

int main(void) {
    ptrdiff_t pd = &pc[INT_MAX] - &pc[0];
    printf("&pc[INT_MAX]=%p; &pc[0]=%p; pc=%p\n", &pc[INT_MAX], &pc[0], pc);
    wchar_t wc = L'Z';
    Str x = {1, 2, 3};
    char *ps = (char*) &x;

    assert(sizeof(ptrdiff_t) == sizeof(size_t));
    assert(offs[0] < offs[1]);
    assert(*(char *)(ps + offs[0]) == 1);
    assert(*(float *)(ps + offs[1]) == 2);
    assert(*(int *)(ps + offs[2]) == 3);

    return 0;
}

