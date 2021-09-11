#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512 // 1行のサイズ
#define MAX_NAME    50  // 氏名を格納する配列のサイズ
#define MAX_STUDENT 100 // 最大の学生数
#define MAX_TEN     5   // 教科数

// 使用法
char *usage[] = {
    "名前",
    "    12stat - かんたん成績処理",
    "書式",
    "    12stat 入力ファイル [出力ファイル]",
    "解説",
    "    プログラム12stat は、",
    "    入力ファイルから生徒の出席番号、名前と各教科の点数を受け取り、",
    "    成績順に並べたり、平均点を求めたりして、結果を出力ファイルに書き出します。",
    "    出力ファイルが指定されていない場合には、標準出力に出力します。",
    "入力",
    "    成績データは個人ごとに1行にまとめて下記、左から順に、",
    "    <出席番号> <氏名> <点数1> <点数2> <点数3> <点数4> <点数5>",
    "    の順で記入します。",
    "入力例",
    "    101 佐藤花子 65 90 100 80 73",
    "    102 阿部和馬 82 75 63 21 45",
    "    103 伊藤光一 74 31 41 59 38",
    "出力",
    "    ・出席番号順の名簿",
    "    ・全教科の合計点に夜成績順位表、平均点・最高点・最低点",
    "    ・合計点の平均",
    NULL,
};

// 学生を表す構造体
typedef struct student {
    int id;              // 出席番号
    char name[MAX_NAME]; // 氏名
    int ten[MAX_TEN];    // 教科ごとの点数
    double total;        // 教科の合計点
} STUDENT;

// データを表す構造体
typedef struct data {
    int size;                     // 学生数
    STUDENT student[MAX_STUDENT]; // 学生の配列
} DATA;

// プロトタイプ宣言
int main(int argc, char *argv[]);
int input_data(FILE *fp, DATA *data);
void sort_by_id(DATA *data);
void sort_by_total(DATA *data);
void swap_student(STUDENT *p, STUDENT *q);
void fprint_data(FILE *fp, DATA *data);
void fprint_stat(FILE *fp, DATA *data);
void print_usage(void);

// 入力ファイルから学生のデータを読み込んで処理する
int main(int argc, char *argv[])
{
    DATA data; // データを格納する変数

    // コマンドラインの解析とファイルのオープン
    if (argc != 2 && argc != 3) {
        print_usage();
        return 0;
    }

    FILE *infp = fopen(argv[1], "r");
    if (infp == NULL) {
        fprintf(stderr, "入力ファイル %s が見つかりません。\n", argv[1]);
        return -1;
    }

    FILE *outfp = stdout;
    if (argc == 3) {
        outfp = fopen(argv[2], "w");
        if (outfp == NULL) {
            fprintf(stderr, "出力ファイル %s が見つかりません。\n", argv[2]);
            fclose(infp);
            return -1;
        }
    }

    // データを読み込む
    if ( input_data(infp, &data) < 0 ) {
        fprintf(stderr, "データ読み込みでエラーが起きました。\n");
        return -1;
    }

    // 学生数を表示する
    fprintf(outfp, "== 学生数 ==\n");
    fprintf(outfp, "%d 人\n", data.size);
    fprintf(outfp, "\n");

    // 出席番号順で並べ替え、名簿を表示する
    fprintf(outfp, "==　出席番号順の名簿 ==\n");
    sort_by_id(&data);
    fprint_data(outfp, &data);
    fprintf(outfp, "\n");

    // 合計点順で並べ替え、名簿を表示する
    fprintf(outfp, "== 合計点による成績順位表 ==\n");
    sort_by_total(&data);
    fprint_data(outfp, &data);
    fprintf(outfp, "\n");

    // 平均点・最高点・最低点を表示する
    fprintf(outfp, "== 平均点・最高点・最低点 ==\n");
    fprint_stat(outfp, &data);
    fprintf(outfp, "\n");

    if ( fclose(outfp) ) {
        printf("出力ファイルのクローズでエラーが起きました。\n");
        fclose(infp);
        return -1;
    }

    if ( fclose(infp) ) {
        printf("入力ファイルのクローズでエラーが起きました。\n");
        return -1;
    }

    return 0;

}

// input_dataはファイルからデータを読み込む
int input_data(FILE *infp, DATA *dp)
{
    char buffer[BUFFER_SIZE];
    char name_buffer[BUFFER_SIZE];
    int n = 0; // 現在処理している学生数

    while ( fgets(buffer, BUFFER_SIZE, infp) != NULL ) {
        if (n >= MAX_STUDENT) {
            fprintf(stderr, "学生数が多すぎます(最大 %d 人)\n", MAX_STUDENT);
            return -1;
        }

        // ファイルから読み込んだ学生データを代入する学生へのポインタ
        STUDENT *sp = &dp->student[n];

        // 関数sscanfを使ってデータを解析
        int num = sscanf(buffer, "%d %s %d %d %d %d %d\n",
                &sp->id,
                &name_buffer[0],
                &sp->ten[0],
                &sp->ten[1],
                &sp->ten[2],
                &sp->ten[3],
                &sp->ten[4]);
        if (num != 7) {
            fprintf(stderr, "%d 行目で形式が誤っています。\n", n + 1);
            fprintf(stderr, "%s\n", buffer);
            return -1;
        }

        // 氏名の長さをチェックしてオーバーフローを防ぐ
        if ( strlen(name_buffer) + 1 > MAX_NAME ) {
            fprintf(stderr, "%d 行目の名前は長すぎます\n", n + 1);
            fprintf(stderr, "(最大 %d バイト)\n", MAX_NAME - 1);
            fprintf(stderr, "%s\n", name_buffer);
            return -1;
        }

        // 氏名をコピー
        strcpy(sp->name, name_buffer);

        // 学生の教科合計点を計算
        sp->total = 0;
        for (int i = 0; i < MAX_TEN; i++) {
            sp->total += sp->ten[i];
        }

        // 学生数の更新
        n++;
    }

    // 学生数
    dp->size = n;

    // 学生数を返す
    return dp->size;

}

// 関数 swap_student は STUDENT を交換する
void swap_student(STUDENT *p, STUDENT *q)
{
    STUDENT s = *p;
    *p = *q;
    *q = s;
}

// 関数 sort_by_id は出席番号順で並べ替えを行う
void sort_by_id(DATA *dp)
{
    for (int i = 0; i < dp->size; i++) {
        STUDENT *sp1 = &dp->student[i]; // i番目の学生
        for (int j = i + 1; j < dp->size; j++) {
            STUDENT *sp2 = &dp->student[j]; // j番目の学生
            if (sp1->id > sp2->id) { // 出席番号を比較
                swap_student(sp1, sp2);
            }

        }
    }
}

// 関数 sort_by_total は合計点順で並べ替えを行う
void sort_by_total(DATA *dp)
{
    for (int i = 0; i < dp->size - 1; i++) {
        STUDENT *sp1 = &dp->student[i]; // i番目の学生
        for (int j = i + 1; j < dp->size; j++) {
            STUDENT *sp2 = &dp->student[j]; // j番目の学生
            if (sp1->total < sp2->total) { // 合計点を比較
                swap_student(sp1, sp2);
            }
        }

    }
}

// 関数 fprint_data はデータを表示する
void fprint_data(FILE *fp, DATA *data) {
    for (int n = 0; n < data->size; n++) {
        STUDENT *sp = &data->student[n];

        // 連番
        fprintf(fp, "%3d) ", n + 1);
        // 点数
        for (int i = 0; i < MAX_TEN; i++) {
            fprintf(fp, "%3d ", sp->ten[i]);
        }
        // 出席番号
        fprintf(fp, "出席番号 %3d ", sp->id);
        // 合計点
        fprintf(fp, "合計点 %0.1f ", sp->total);
        // 平均点
        fprintf(fp, "平均点 %0.1f ", sp->total / MAX_TEN);
        // 氏名
        fprintf(fp, "氏名 %s", sp->name);
        fprintf(fp, "\n");
    }
}

// 関数 fprint_stat() は、教科ごとの平均点・最高点・最低点を計算し、
// 表示する。また合計点の平均も表示する。
void fprint_stat(FILE *fp, DATA *data)
{
    int max[MAX_TEN]; // 教科ごとの最高点
    int min[MAX_TEN]; // 教科ごとの最低点
    double ten[MAX_TEN]; // 教科ごとの平均点
    double total; // 合計点の平均点
    STUDENT *sp;

    // 0番目の学生のデータで初期化
    sp = &data->student[0];
    for (int i = 0; i < MAX_TEN; i++) {
        max[i] = sp->ten[i];
        min[i] = sp->ten[i];
        ten[i] = sp->ten[i];
    }
    total = sp->total;

    // 統計計算
    for (int n = 0; n < data->size; n++) {
        sp = &data->student[n];
        for (int i = 0; i < MAX_TEN; i++)
        {
            if (max[i] < sp->ten[i]) {
                max[i] = sp->ten[i];
            }
            if (min[i] > sp->ten[i]) {
                min[i] = sp->ten[i];
            }
            ten[i] += sp->ten[i];
        }
        total += sp->total;
    }

    // 結果の出力
    for (int i = 0; i < MAX_TEN; i++)
    {
        fprintf(fp, "教科 %d ", i + 1);
        fprintf(fp, "最高点 %3d ", max[i]);
        fprintf(fp, "最低点 %3d ", min[i]);
        fprintf(fp, "平均点 %0.1f\n", ten[i] / data->size);
    }
    fprintf(fp, "合計点の平均 %0.1f\n", total / data->size);
}

// 使用法の表示
void print_usage(void)
{
    for (int i = 0; usage[i] != NULL; i++) {
        printf("%s\n", usage[i]);
    }
}