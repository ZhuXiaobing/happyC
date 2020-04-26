//
// Created by zhuxiaobing on 4/14/2020.
//
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "funcha.h"

int main() {
    Car *car = getCar(4, square);
    int i=0;
    int j=0;
    i++,j++;
    printf("%d,%d\n",car->wheels, car->sw);
    scanf("%d",&i);
    printf("%d\n", i);
    free(car);
    getchar();
}
