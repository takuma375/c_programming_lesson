#include <stdio.h>

int main(void);
int add(int a, int b);

int add(int a, int b)
{
    int c = a + b;
    return c;
}

int main(void)
{
    int x = 100;
    int y = 20;
    int z = add(x, y);
    printf("%d + %d を計算すると %d になります。\n", x, y, z);
    return 0;
}
