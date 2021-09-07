#include <stdio.h>

int main(void);

int main(void)
{
    int ten[3];

    ten[0] = 65;
    ten[1] = 90;
    ten[2] = 75;

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum = sum + ten[i];
    }
    double heikin = sum / 3.0;
    printf("国語は %d 点\n", ten[0]);
    printf("数学は %d 点\n", ten[1]);
    printf("英語は %d 点\n", ten[2]);
    printf("平均点は %0.1f 点\n", heikin);

    return 0;

}
