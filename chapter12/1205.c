#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]);
void print_usage(void);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("使用法: %s 入力ファイル 出力ファイル\n", argv[0]);
        print_usage();
        return -1;
    }

    char *infile = argv[1];
    char *outfile = argv[2];

    printf("入力ファイル: %s\n", infile);
    printf("出力ファイル: %s\n", outfile);

    FILE *infp = fopen(infile, "r");
    if (infp == NULL) {
        printf("ファイル %s が見つかりません。\n", infile);
        return -1;
    }

    FILE *outfp = fopen(outfile, "w");
    if (outfp == NULL) {
        printf("ファイル %s が作れません。\n", outfile);
        fclose(infp);
        return -1;
    }

    long linenumber = 1L;
    char buffer[BUFFER_SIZE];

    while ( fgets(buffer, BUFFER_SIZE, infp) != NULL ) {
        fprintf(outfp, "%08ld: %s", linenumber, buffer);
        linenumber++;
    }

    if (fclose(outfp)) {
        printf("ファイル %s のクローズでエラーが起きました。\n", outfile);
        fclose(infp);
        return -1;
    }

    if (fclose(infp)) {
        printf("ファイル %s のクローズでエラーが起きました。\n", infile);
        return -1;
    }
}

// 使用法の表示
void print_usage(void)
{
    printf("各行の先頭に行番号を付けて出力します。\n");
    printf("1行の最大サイズは%dバイトです。\n", BUFFER_SIZE);
}
