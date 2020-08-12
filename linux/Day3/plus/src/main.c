#include <stdio.h>
#include "head.h"

int main(void)
{
    int a = 125;
    printf("========== =_= ==========\n");
    printf("%d + %d = %d\n", a, a, add(a,a));
    printf("%d - %d = %d\n", a, a, sub(a,a));
    printf("%d * %d = %d\n", a, a, mul(a,a));
    printf("=========================\n");
	return 0;
}
