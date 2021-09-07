#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 256 // 1行のサイズ

#define MAX_DATA 500 // 処理できるデータの個数

// 大域変数
double data[MAX_DATA];  // データを格納する配列
int size_data = 0;
double sum_data;
double ave_data;
double max_data;
double min_data;
double mid_data;

// 関数宣言
int main(void);
void input_data(void);
void calc_stats(void);
void output_data(void);

int main(void)
{
    input_data();
    calc_stats();
    output_data();
    return 0;
}

// 標準入力からデータを入力し、大域変数dataに格納する
void input_data(void)
{
    char buffer[BUFFER_SIZE];

    while ( fgets(buffer, BUFFER_SIZE, stdin) != NULL ) {
        if (size_data >= MAX_DATA) {
            printf("処理できるデータサイズを超えました。\n");
            printf("データサイズは最大 %d 個です。\n", MAX_DATA);
            exit(-1);
        } else if (isdigit(buffer[0]) || buffer[0] == '.') {
            data[size_data] = (double)atof(buffer);
            size_data++;
        } else {
            // 数字または . で始まらない行はそのまま表示する
            printf("%s", buffer);
        }
    }
}

// 配列dataに入っているデータを元に各種統計情報を計算し、大域変数に格納する。
void calc_stats(void)
{
    // 合計の計算
    sum_data = 0.0;
    for (int i = 0; i < size_data; i++) {
        sum_data += data[i];
    }

    // 平均値の計算
    ave_data = sum_data / size_data;

    // 最大値・最小値の計算
    if (size_data > 0) {
        min_data = data[0];
        max_data = data[0];
    }
    for (int i = 0; i < size_data; i++) {
        if (min_data > data[i]) {
            min_data = data[i];
        }
        if (max_data < data[i]) {
            max_data = data[i];
        }
    }

    // 中央値の計算
    // 一旦データを小さい順序に並べ替える
    for (int i = 0; i < size_data; i++) {
        for (int j = i + 1; j < size_data; j++) {
            if (data[i] > data[j]) {
                double tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
    mid_data = data[size_data / 2];

}

// 関数output_dataは、大域変数に格納された統計情報を表示する
void output_data(void)
{
    printf("データサイズ %d \n", size_data);
    printf("合計 %0.1f \n", sum_data);
    printf("平均値 %0.1f \n", ave_data);
    printf("最大値 %0.1f \n", max_data);
    printf("最小値 %0.1f \n", min_data);
    printf("中央地 %0.1f \n", mid_data);
}
