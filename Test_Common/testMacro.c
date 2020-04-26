#define myfun(i) (i+i)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* (myfun)(int i) { //为了避免被宏替换，此时的方法名可以括起来，标准库常用技巧。
    char str[11]; 
    itoa(i, str, 10);
    char *prefix = "this is i=";
    char *suffix = ", hahaha";
    char *res = (char *)malloc(strlen(prefix) + strlen(str) + strlen(suffix));
    sprintf(res, "%s%s%s", prefix, str, suffix);
    return res;
}

int main(void) {
    
    int i = myfun(1);  // 如果去掉首行“#define myfun(i) (i+i)” 这个宏定义，那么此处会调用上面的函数体，因类型不匹配，结果不确定。
    printf("%d\n", i);

    char *res = (myfun)(5); // 函数名括起来，避免宏替换。
    printf("%s\n", res);

    return 0;
}
