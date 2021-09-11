// 16進ダンププログラム
#include <stdio.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    printf("16進ダンププログラム\n");
    if (argc != 2) {
        printf("使用法: %s ファイル名\n", argv[0]);
        return -1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("ファイル %s が見つかりません。\n", filename);
        return -1;
    }

    long offset = 0L;
    int c;
    while ( (c = fgetc(fp)) != EOF)
    {
        int column = offset % 16;
        if (column == 0) {
            printf("%08lX : ", offset);
        }
        printf("%02X", (unsigned char)c);
        if (column == 7) {
            printf("-");
        } else {
            printf(" ");
        }
        if (column == 15) {
            printf("\n");
        }
        offset++;
    }
    printf("\n");
    
    if ( fclose(fp) ) {
        printf("ファイル %s のクローズでエラーが起きました。\n", filename);
    }

    return 0;
}
