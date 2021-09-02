#include <stdio.h>

int main(void);

int main(void)
{
    for (int i=0; i<11; i++) {
        printf("%2d × %2d = %3d\n", i, i, i * i);
    }
    return 0;
}
