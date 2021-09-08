#include <stdio.h>

int main(void);
void quiz(char c, char *p);

void quiz(char c, char *p)
{
    printf("quiz 1: %c, %c\n", c, *p);

    c = 'C';
    *p = 'P';

    printf("quiz 2: %c, %c\n", c, *p);
}

int main(void)
{
    char a = 'A';
    char b = 'B';

    printf("main 1: %c, %c\n", a, b);

    quiz(a, &b);

    printf("main 2: %c, %c\n", a, b);

    return 0;
}
