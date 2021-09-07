#include <stdio.h>

int main(void);

int main(void)
{
    int a[10];

    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            a[i] = 0;
        } else {
            a[i] = a[i - 1] + i;
        }
        printf("[%d] = %d\n", i, a[i]);
    }
    printf("%d\n", a[5]);
    return 0;
}
