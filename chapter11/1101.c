#include <stdio.h>

void swap_int(int *xp, int *yp);
int main(void);

void swap_int(int *xp, int *yp)
{
    int tmp;

    tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

int main(void)
{
    int x = 123;
    int y = 456;

    printf("x: %d, y: %d\n", x, y);
    swap_int(&x, &y);
    printf("x: %d, y: %d\n", x, y);

    return 0;
}
