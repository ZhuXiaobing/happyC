#include<assert.h>
#include<stdio.h>

int main() {
    #ifdef NDEBUG
        printf("通过make CFLAGS=-DNODEBUG编译执行，make 指定-DNDEBUG,下面的assert不会执行\n");
        assert(1>2);
    #else
        printf("通过make CFLAGS=编译执行，make 没有指定-DNDEBUG,下面的assert会执行\n");
        assert(1>2);
    #endif
}