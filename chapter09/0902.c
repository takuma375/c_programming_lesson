#include <stdio.h>

int main(void);

int main(void)
{
    int ten[3];
    double heikin;

    ten[0] = 65;
    ten[1] = 90;
    ten[2] = 75;
    heikin = (ten[0] + ten[1] + ten[2]) / 3.0;

    printf("国語は %d 点\n", ten[0]);
    printf("数学は %d 点\n", ten[1]);
    printf("英語は %d 点\n", ten[2]);
    printf("平均点は %0.1f 点\n", heikin);

    return 0;

}
