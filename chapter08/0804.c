#include <stdio.h>

int get_power(int x, int n);
int main(void);

// x の n 乗の計算
int get_power(int x, int n)
{
    int y = 1;
    for (int i = 0; i < n; i++) {
        y *= x;
    }
    return y;
}

int main(void)
{
    printf("%d\n", get_power(8, 2));
    return 0;
}
