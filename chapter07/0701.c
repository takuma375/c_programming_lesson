#include <stdio.h>

int main(void);

int main(void)
{
    int i = 0;

    while (i < 3) {
        printf("%d\n", i);
        i++;
    }

    printf("end\n");

    return 0;
}
