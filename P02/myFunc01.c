//
// Created by zhuxiaobing on 4/14/2020.
//
#include <stdio.h>
#include <malloc.h>
#include "funcha.h"
#include "funchb.h"

Car * getCar(int wheels, enum steerwheel sw) {
    Car *car = malloc(sizeof(Car));
    car->wheels = wheels;
    car->sw = sw;
    return car;
}
