#include <stdio.h>

int main(void);
int square(int top, int bottm, int height);

int main(void)
{
    printf("%d", square(2, 3, 4));
    return 0;
}

int square(int top, int bottom, int height)
{
    int area = (top + bottom) * height / 2;
    return area;
}
