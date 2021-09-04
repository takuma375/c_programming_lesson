#include <stdio.h>

int main(void);

int main(void)
{
    for (int i=0; i < 10; i++) {
        printf("%d の2乗は %d で、", i, i * i);
        printf("3乗は %d です。\n", i * i * i);
    }

    return 0;
}
