#include <stdio.h>

#define MAX_TEN 5

int main(void);

int main(void)
{
    int ten[MAX_TEN];

    ten[0] = 65;
    ten[1] = 90;
    ten[2] = 75;
    ten[3] = 45;
    ten[4] = 82;

    int sum = 0;
    for (int i = 0; i < MAX_TEN; i++) {
        sum = sum + ten[i];
    }

    double heikin = (double)sum / MAX_TEN;

    printf("国語は %d 点\n", ten[0]);
    printf("数学は %d 点\n", ten[1]);
    printf("英語は %d 点\n", ten[2]);
    printf("理科は %d 点\n", ten[3]);
    printf("社会は %d 点\n", ten[4]);
    printf("平均点は %0.1f 点\n", heikin);

    return 0;
}
