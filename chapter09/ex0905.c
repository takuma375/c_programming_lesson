#include <stdio.h>

int main(void);

int main(void)
{
    int data[] = { 31, 41, 59, 26, 53, 58, 97, 93, 23, 84 };
    int maxdata = data[0];

    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
        if (maxdata < data[i]) {
            maxdata = data[i];
        }
    }

    printf("最大値は %d です。\n", maxdata);
    return 0;
}
