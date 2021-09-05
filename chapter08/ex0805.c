#include <stdio.h>

int get_power(int x, int n);
void graph(int x);
int main(void);

int get_power(int x, int n)
{
    int y = 1;
    for (int i = 0; i < n; i++) {
        y *= x;
    }
    return y;
}

void graph(int x)
{
    for (int i = 0; i < x; i++) {
        printf("*");
    }
    printf("\n");
}

int main(void)
{
    for (int i = -8; i <= 8; i++) {
        printf("%2d: ", i);
        graph(get_power(i, 2));
    }

    return 0;
}
