#include <stdio.h>
#include <limits.h>

int main(void);

int main(void)
{
    printf("このコンパイラが\n");
    printf("\n");

    printf("char 型で扱える最小値は %d です。\n", CHAR_MIN);
    printf("char 型で扱える最大値は %d です。\n", CHAR_MAX);
    printf("\n");

    printf("int 型で扱える最小値は %d です。\n", INT_MIN);
    printf("int 型で扱える最大値は %d です。\n", INT_MAX);
    printf("\n");

    printf("long 型で扱える最小値は %ld です。\n", LONG_MIN);
    printf("long 型で扱える最大値は %ld です。\n", LONG_MAX);
    printf("\n");

    return 0;
}
