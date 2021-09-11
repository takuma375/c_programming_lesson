#include <stdio.h>

int main(void);
void get_line(char *buffer, int size);

int main(void)
{
    printf("ファイルをコピーするプログラム\n");

    printf("コピーもとのファイル名を入力してください。\n");
    char fromfile[FILENAME_MAX];
    get_line(fromfile, FILENAME_MAX);
    FILE *fromfp = fopen(fromfile, "rb");
    if (fromfp == NULL) {
        printf("ファイル %s が見つかりません。\n", fromfile);
        return -1;
    }

    printf("コピー先のファイル名を入力してください。\n");
    char tofile[FILENAME_MAX];
    get_line(tofile, FILENAME_MAX);
    FILE *tofp = fopen(tofile, "wb");
    if (tofp == NULL) {
        printf("ファイル %s が作れません。\n", tofile);
        fclose(fromfp);
        return -1;
    }

    int c;
    while ( (c = fgetc(fromfp)) != EOF ) {
        fputc(c, tofp);
    }

    if ( fclose(tofp) ) {
        printf("ファイル %s のクローズでエラーが起きました。\n", tofile);
        fclose(fromfp);
        return -1;
    }

    if ( fclose(fromfp) ) {
        printf("ファイル %s のクローズでエラーが起きました。\n", fromfile);
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
