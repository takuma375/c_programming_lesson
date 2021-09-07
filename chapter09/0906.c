#include <stdio.h>

int main(void);

int main(void)
{
    unsigned char name[] = "ABC 123 ワンパチ";

    for (int i = 0; name[i] != '\0'; i++) {
        printf("%02X ", name[i]);
    }
    printf("\n");
    printf("%s\n", &name[0]);

    return 0;
}
