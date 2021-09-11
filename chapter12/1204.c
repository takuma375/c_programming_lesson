#include <stdio.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    printf("テキストファイルをコピーするプログラム\n");
    if (argc != 3) {
        printf("使用方法: %s FILE1 FILE2\n", argv[0]);
        printf("FILE1 の内容を FILE2 にコピーします。\n");
        return -1;
    }

    char *infile = argv[1];
    char *outfile = argv[2];

    FILE *infp = fopen(infile, "r");
    if (infp == NULL) {
        printf("ファイル %s が見つかりません。\n", infile);
        return -1;
    }

    FILE *outfp = fopen(outfile, "w");
    if (outfp == NULL) {
        printf("ファイル %s が見つかりません。\n", outfile);
        fclose(infp);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    while ( fgets(buffer, BUFFER_SIZE, infp) != NULL ) {
        fputs(buffer, outfp);
    }

    if ( fclose(outfp) ) {
        printf("ファイル %s のクローズでエラーが起きました。\n", outfile);
        fclose(infp);
        return -1;
    }

    if ( fclose(infp) ) {
        printf("ファイル %s のクローズでエラーが起きました。\n", infile);
        return -1;
    }

    return 0;
}
