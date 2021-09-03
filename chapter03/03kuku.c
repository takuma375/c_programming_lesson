#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Q 10         // 表示する問題の個数
#define BUFFER_SIZE 256  // 入力行の最大長

// プロトタイプ宣言
int main(void);
int kuku(int qn);
void get_line(char *buffer, int size);

int main(void)
{
    double good_rate; // 正答率
    int good_answers = 0; // 正答数合計

    // 現在時刻を使って乱数の「種」を設定する
    srand((unsigned int)time(NULL));

    printf("これから九九の問題を %d 問出します。\n", MAX_Q);

    good_answers = 0;
    for (int i=0; i < MAX_Q; i++) {
        good_answers += kuku(i);
    }

    // 正答率を計算する
    good_rate = good_answers * 100.0 / MAX_Q;

    printf("\n");
    // 結果を表示する
    printf("問題は %d 問ありました。\n", MAX_Q);
    printf("%d 問は正しく答えられましたが、\n", good_answers);
    printf("%d 問は間違ってしまいました。\n", MAX_Q - good_answers);
    printf("正答率 %0.1f %%です。\n", good_rate);
    printf("\n");
    printf("おつかれさま。\n");

    return 0;
}

int kuku(int qn)
{
    int x, y, result;
    char buffer[BUFFER_SIZE];

    // 問題をランダムに生成する
    x = rand() % 9 + 1;
    y = rand() % 9 + 1;

    // 出題する。
    printf(" [第 %d 問]   %d × %d = ", qn + 1, x, y);

    // 端末が開業街で表示を抑止するのを防ぐ
    fflush(stdout);

    // 回答の入力を待つ。
    get_line(buffer, BUFFER_SIZE);

    // 解答を整数に変換する
    result = atoi(buffer);

    // 正答か誤答か確認する
    if (x * y == result) {
        printf("はい、正しいです！\n");
        return 1;
    } else {
        printf("残念、間違いです。\n");
        return 0;
    }
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
