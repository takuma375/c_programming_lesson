#include <stdio.h>

int main(void);

int main(void)
{
    char a[7];

    a[0] = 'H';
    a[1] = 'e';
    a[2] = 'l';
    a[3] = 'l';
    a[4] = 'o';
    a[5] = '\n';
    a[6] = '\0';

    for (int i = 0; a[i] != '\0'; i++) {
        printf("%c", a[i]);
    }

    printf("%s", &a[0]);

    return 0;
}
