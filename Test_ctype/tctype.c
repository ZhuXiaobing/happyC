#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>

static void prclass(const char *name, int (*fn)(int)) {
    int c;
    fputs(name, stdout);
    fputs(":", stdout);
    for (c = EOF; c <= UCHAR_MAX; ++c) {
        if ((*fn)(c)) {
            fputc(c, stdout);
        }
    }
    fputs("\n", stdout);
}

int main() {
    char *s;
    int c;
    prclass("ispunct", &ispunct);
    prclass("isdigit", &isdigit);
    prclass("islower", &islower);
    prclass("isupper", &isupper);
    prclass("isalpha", &isalpha);
    prclass("isalnum", &isalnum);
    return 0 ;
}