#include <stdio.h>

int main(void);

int main(void)
{
    for (int i=0; i < 10; i++) {
        printf("%d ", i);

        for (int j=0; j < i * i; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
