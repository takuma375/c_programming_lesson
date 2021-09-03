#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main(void);
void get_line(char *buffer, int size);

int main(void)
{
    char buffer[BUFFER_SIZE];
    int n;

    printf("降水確率を入力してください。\n");
    get_line(buffer, BUFFER_SIZE);
    n = atoi(buffer);

    printf("降水確率は %d %%です。\n", n);

    if (n > 100) {
        printf("降水確率は 0 〜 100 の間ですよ。\n");
    } else if (n >= 50) {
        printf("傘を忘れずにね。\n");
    } else {
        printf("傘はいりません。\n");
    }

    printf("いってらっしゃい。\n");

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
