// ファイルの最初の5行を表示するプログラム
#include <stdio.h>

void print_file(char *filename);
int main(int argc, char *argv[]);

#define LINES 5
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    printf("ファイルの初めの %d 行を表示するプログラム\n", LINES);
    if (argc < 2) {
        printf("使用法: %s ファイル名1 ファイル名2 ... \n", argv[0]);
        return -1;
    }

    for (int i = 1; i < argc; i++) {
        print_file(argv[i]);
        printf("\n");
    }

    return 0;
}

// 指定されたファイルの初めの LINES 行を表示する。
// LINES行までいたらないファイルはファイルの終わりまで表示する
void print_file(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ファイル %s が見つかりません\n", filename);
        return;
    }
    printf("==== %s ====\n", filename);
    for (int i = 0; i < LINES; i++) {
        char buffer[BUFFER_SIZE];
        if ( fgets(buffer, BUFFER_SIZE, fp) == NULL)
        {
            break;
        }
        printf("%s", buffer);
        
    }
    if ( fclose(fp) ) {
        fprintf(stderr, "ファイル %s のクローズでエラーが起きました。\n", filename);
    }
}