#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // 如下很多代码变量声明可能Segmentation fault,记住两点：
    // 1: 如果指针指向的是字符串常量，其值不允许修改。
    // 2: 运行时声明的数组，其大小和地址在运行时不可变
    // 参考：https://www.cnblogs.com/joeymary/p/4931058.html
    
    char str[] = "hello,world";
    char *str2 = "are you ok?";

    printf("str2 is :%s\n", str2);
    printf("str is :%s\n", str);

    char *index = (char*)memchr(str, 'o', 7);
    printf("memchar result is %d;\n", index - str);

    printf("memcpy result is：%d;\n", memcmp(str, str2, 10));
    printf("memcpy result is：%d;\n", memcmp(str, str2, 12));

    memcpy(str, str2, 7); // 如果此处声明为char *str； 则报Segmentation fault.
    printf("memcpy result is :%s\n", str);

    memmove(str, str2, 8); // 如果此处声明为char *str； 则报Segmentation fault.
    printf("memmove result is :%s\n", str);

    char str3[] = "3333helloworld.";
    memset(str3, 'K', 6); // 如果此处声明为char *str3； 则报Segmentation fault.
    printf("memset result is :%s\n", str3);

    char str4[] = "444hello,"; // 如果此处直接声明为char *str4, 则报Segmentation fault.
    char *str4ptr = str4;
    char *str5 = "world";
    strcat(str4ptr, str5);
    printf("strcat result is :%s\n", str4ptr);

    return 0;
}
