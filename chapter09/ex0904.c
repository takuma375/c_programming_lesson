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
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
