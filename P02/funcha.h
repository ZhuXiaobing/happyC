//
// Created by zhuxiaobing on 4/14/2020.
//

#ifndef PRACTICES_MYFUNC0A_H
#define PRACTICES_MYFUNC0A_H

enum steerwheel  {square, circle};
typedef struct {
    int wheels;
    enum steerwheel sw;
} Car;

Car * getCar(int, enum steerwheel);

#endif //PRACTICES_MYFUNC0A_H
