#include <stdio.h>

int main(void);
void get_line(char *buffer, int size);

int main(void)
{
    char filename[FILENAME_MAX];

    printf("ファイルを表示するプログラム\n");
    printf("ファイル名を入力してください。\n");
    get_line(filename, FILENAME_MAX);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ファイル %s が見つかりません。\n", filename);
        return -1;
    }

    int c;
    while ( (c = fgetc(fp)) != EOF ) {
        putchar(c);
    }

    if ( fclose(fp) ) {
        printf("ファイル %s のクローズでエラーが起きました。\n", filename);
        return -1;
    }

    return 0;
}

void get_line(char *buffer, int size)
{
    if ( fgets(buffer, size, stdin) == NULL ) {
        buffer[0] = '\0';
        return;
    }

    for (int i = 0; i < size; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            return;
        }
    }
}
