#include <stdio.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    printf("argc の値は %d です。\n", argc);
    for (int i=0; i < argc; i++) {
        printf("argc[%d]の値は \"%s\" です。\n", i, argv[i]);
    }

    return 0;
}
