#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256 // 1行の最大数
#define DICT_SIZE 100 // 英単語と日本語訳の対の最大数

char *usage[] = {
    "名前",
    "    11dict - 辞書検索",
    "書式",
    "    11dict 辞書ファイル名 英単語",
    "解説",
    "    このプログラムは、",
    "    英単語と日本語訳の書かれたファイル(辞書ファイル)を検索し、",
    "    入力された英単語の日本語訳を表示するものです。",
    "辞書ファイルの例",
    "    dictionary 辞書",
    "    English 英語",
    "    foreign 外国の",
    "    home 家",
    "    end 終了",
    NULL,
};

// 単語の対を格納する構造体の宣言
#define ENGLISH_SIZE 50 // 英単語を格納する配列の大きさ
#define JAPANESE_SIZE 50 // 和訳を格納する配列の大きさ
typedef struct word {
    char english[ENGLISH_SIZE];
    char japanese[JAPANESE_SIZE];
} PAIR;

PAIR dict[DICT_SIZE];
int dict_size = 0;

// プロトタイプ宣言
int main(int argc, char *argv[]);
int input_dict(FILE *fp);

int main(int argc, char *argv[])
{
    FILE *fp; // 辞書ファイル

    // コマンドラインの解析
    if (argc != 3) {
        for (int i = 0; usage[i] != NULL; i++) {
            printf("%s\n", usage[i]);
        }
        return 0;
    }

    // 辞書名
    char *dictfile = argv[1];

    // 検索する単語
    char *english = argv[2];

    // 辞書ファイルのオープン
    fp = fopen(dictfile, "r");
    if (fp == NULL) {
        fprintf(stderr, "辞書ファイル %s が見つかりません。\n", dictfile);
        return -1;
    }

    // 辞書ファイルを読み込む
    if (input_dict(fp) < 0) {
        fprintf(stderr, "辞書ファイル %s の読み込みでエラーが起きました。\n", dictfile);
        fclose(fp);
        return -1;
    }

    // 単語を検索し、見つかったら表示する
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dict[i].english, english) == 0) {
            printf("%s %s\n", dict[i].english, dict[i].japanese);
        }
    }

    return 0;
}

int input_dict(FILE *fp)
{
    char buffer[BUFFER_SIZE];
    char english_buffer[BUFFER_SIZE];
    char japanese_buffer[BUFFER_SIZE];

    // 辞書の読み込み
    dict_size = 0; // 格納されている単語の数
    while ( fgets(buffer, BUFFER_SIZE, fp) != NULL ) {
        if (dict_size >= DICT_SIZE) {
            fprintf(stderr, "単語数が多すぎます(最大 %d 個)。\n", DICT_SIZE);
            fclose(fp);
            return -1;
        }

        // 関数 sscanfを使ってデータを解析
        int num = sscanf(buffer, "%s %s\n",
                english_buffer,
                japanese_buffer);
        if (num != 2) {
            fprintf(stderr, "%d 行目で形式が間違っています。\n", dict_size + 1);
            fprintf(stderr, "%s\n", buffer);
            return -1;
        }

        // 長さをチェックしてオーバーフローを防ぐ
        if (strlen(english_buffer) + 1 > ENGLISH_SIZE) {
            fprintf(stderr, "%d 行目の英単語は長すぎます。", dict_size + 1);
            fprintf(stderr, "(最大 %d バイト)\n", ENGLISH_SIZE - 1);
            fprintf(stderr, "%s\n", english_buffer);
            return -1;
        }

        // 英単語をコピー
        strcpy(dict[dict_size].english, english_buffer);

        // 長さをチェックしてオーバーフローを防ぐ
        if (strlen(japanese_buffer) + 1 > JAPANESE_SIZE) {
            fprintf(stderr, "%d 行目の日本語訳は長すぎます。", dict_size + 1);
            fprintf(stderr, "(最大 %d バイト)\n", JAPANESE_SIZE - 1);
            fprintf(stderr, "%s\n", japanese_buffer);
            return -1;
        }

        // 日本語訳をコピー
        strcpy(dict[dict_size].japanese, japanese_buffer);

        // 単語対の数を更新
        dict_size++;
    }

    return dict_size;
}
