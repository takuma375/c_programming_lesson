#include <stdio.h>

int main(void);

int main(void)
{
    int kokugo, suugaku, eigo;
    double heikin;

    kokugo = 65;
    suugaku = 90;
    eigo = 75;
    heikin = (kokugo + suugaku + eigo) / 3.0;

    printf("国語は %d 点\n", kokugo);
    printf("数学は %d 点\n", suugaku);
    printf("英語は %d 点\n", eigo);
    printf("平均点は %0.1f 点\n", heikin);

    return 0;
}
