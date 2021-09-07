#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    int kokugo;
    int suugaku;
    int eigo;
    int rika;
    int syakai;
};

int main(void);
void print_student(struct student s);

int main(void)
{
    struct student taro;

    taro.id = 10;
    strcpy(&taro.name[0], "Yamada");
    taro.kokugo = 100;
    taro.suugaku = 85;
    taro.eigo = 60;
    taro.rika = 95;
    taro.syakai = 73;

    print_student(taro);
    return 0;
}

void print_student(struct student s)
{
    printf("出席番号:%d\n", s.id);
    printf("氏名: %s\n", &s.name[0]);
    printf("国語: %d\n", s.kokugo);
    printf("数学: %d\n", s.suugaku);
    printf("英語: %d\n", s.eigo);
    printf("理科: %d\n", s.rika);
    printf("社会: %d\n", s.syakai);
    printf("合計: %d\n", s.kokugo + s.suugaku + s.eigo + s.rika + s.syakai);
    printf("\n");
}
