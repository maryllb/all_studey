#include <stdio.h>
#include <string.h>
#include "head.h"
#include <unistd.h>

int add(int a, int b)
{
    int result = a + b;
    printf("这是一个加法运算!\n");
    return result;
}
