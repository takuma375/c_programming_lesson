#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    int ten[5];
};

void print_student(struct student s);
int main(void);

int main(void)
{
    struct student taro;

    taro.id = 10;
    strcpy(&taro.name[0], "Yamada");
    taro.ten[0] = 100;
    taro.ten[1] = 85;
    taro.ten[2] = 60;
    taro.ten[3] = 95;
    taro.ten[4] = 73;

    print_student(taro);
    return 0;
}

void print_student(struct student s)
{
    int total;

    printf("出席番号: %d\n", s.id);
    printf("氏名: %s\n", &s.name[0]);
    printf("国語: %d\n", s.ten[0]);
    printf("数学: %d\n", s.ten[1]);
    printf("英語: %d\n", s.ten[2]);
    printf("理科: %d\n", s.ten[3]);
    printf("社会: %d\n", s.ten[4]);

    total = 0;
    for (int i = 0; i < 5; i++) {
        total += s.ten[i];
    }
    printf("合計: %d\n", total);
    printf("\n");
}
