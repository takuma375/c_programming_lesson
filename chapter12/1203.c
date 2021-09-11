#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    printf("ファイルをコピーするプログラム\n");
    if (argc != 3) {
        printf("使用方法: %s FILE1 FILE2\n", argv[0]);
        printf("FILE1 の内容を FILE2 にコピーします。\n");
        return -1;
    }

    char *fromfile = argv[1];
    char *tofile = argv[2];

    FILE *fromfp = fopen(fromfile, "rb");
    if (fromfp == NULL) {
        printf("ファイル %s が見つかりません。\n", fromfile);
        return -1;
    }

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
