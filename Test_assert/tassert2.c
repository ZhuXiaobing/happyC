#include<assert.h>
#include<stdio.h>

int main() {
    #ifdef NDEBUG
        printf("ͨ��make CFLAGS=-DNODEBUG����ִ�У�make ָ��-DNDEBUG,�����assert����ִ��\n");
        assert(1>2);
    #else
        printf("ͨ��make CFLAGS=����ִ�У�make û��ָ��-DNDEBUG,�����assert��ִ��\n");
        assert(1>2);
    #endif
}