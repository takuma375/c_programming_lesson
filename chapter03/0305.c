#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main(void);
void get_line(char *buffer, int size);

int main(void)
{
    char buffer[BUFFER_SIZE];
    int age;

    printf("あなたの名前を入力してください\n");
    get_line(buffer, BUFFER_SIZE);
    printf("%s さん、こんにちは。\n", buffer);

    printf("\n");

    printf("年齢を入力してください。\n");
    get_line(buffer, BUFFER_SIZE);
    age = atoi(buffer);

    printf("いま %d 歳とすると、10年後は %d 歳ですね。\n", age, age + 10);

    return 0;
}

void get_line(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }

    for (int i=0; i < size; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            return;
        }
    }
}
