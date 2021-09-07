#include <stdio.h>

struct student {
    int id;
    char name[50];
    int kokugo;
    int suugaku;
    int eigo;
};

struct student data[4] = {
    { 1, "結城浩", 65, 90, 100 },
    { 2, "阿部和馬", 82, 73, 63 },
    { 3, "伊藤光一", 74, 31, 41 },
    { 4, "佐藤太郎", 100, 95, 98 },
};

int main(void);

int main(void)
{
    int kokugo = 0, suugaku = 0, eigo = 0;

    for (int i = 0; i < 4; i++) {
        kokugo += data[i].kokugo;
        suugaku += data[i].suugaku;
        eigo += data[i].eigo;
    }

    printf("国語の平均点は %0.1f 点です。\n", kokugo / 4.0);
    printf("数学の平均点は %0.1f 点です。\n", suugaku / 4.0);
    printf("英語の平均点は %0.1f 点です。\n", eigo / 4.0);
    return 0;
}

