#include <stdio.h>

int main(void);

int main(void)
{
    int a[10];

    for (int i = 0; i < 10; i++) {
        a[i] = i * i;
    }
    printf("%d\n", a[5]);
    return 0;
}
