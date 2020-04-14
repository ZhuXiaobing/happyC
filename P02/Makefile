# 定义-g ，以方便调试。
gcc=gcc -g 
MainTest: MainTest.o myFunc01.o funcha.h funchb.h
	${gcc} -o MainTest MainTest.o myFunc01.o
myFunc01.o: myFunc01.c funcha.h
	${gcc} -c myFunc01.c
MainTest.o: MainTest.c funcha.h
	${gcc} -c MainTest.c
.PHONY: clean
clean:
	rm MainTest myFunc01.o MainTest.o