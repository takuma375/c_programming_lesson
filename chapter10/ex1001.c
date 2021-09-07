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
void print_total(struct student s);

int main(void)
{
    for (int i = 0; i < 4; i++) {
        print_total(data[i]);
    }
    return 0;
}

void print_total(struct student s)
{
    printf("%d %s の合計点は", s.id, &s.name[0]);
    printf(" %d 点です。\n", s.kokugo + s.suugaku + s.eigo);
}
