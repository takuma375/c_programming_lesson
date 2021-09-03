#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

// プロトタイプ宣言
int main(void);
void get_line(char *buffer, int size);

int main(void)
{
    char buffer[BUFFER_SIZE];

    char first_name[BUFFER_SIZE];
    char second_name[BUFFER_SIZE];

    double first_age;
    double second_age;
    double average_age;

    printf("2人の平均年齢を計算します。\n");
    printf("1人目の名前を入力してください。\n");

    get_line(first_name, BUFFER_SIZE);

    printf("%s さんの年齢を入力してください。\n", first_name);
    get_line(buffer, BUFFER_SIZE);
    first_age = atoi(buffer);

    printf("2人目の名前を入力してください。\n");
    get_line(second_name, BUFFER_SIZE);

    printf("%s さんの年齢を入力してください。\n", second_name);
    get_line(buffer, BUFFER_SIZE);
    second_age = atoi(buffer);

    average_age = (first_age + second_age) / 2;

    printf("%s さんと %s さんの平均年齢は %0.1f 歳です。\n", first_name, second_name, average_age);

    return 0;

}

void get_line(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }

    for (int i=0; i<size; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            return;
        }
    }
}
