// かんたん成績処理

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512  // 1行のサイズ
#define MAX_NAME 50      // 氏名を格納する配列のサイズ
#define MAX_STUDENT 100  // 学生の最大数
#define MAX_TEN 5        // 教科数

// 学生を表す構造体
struct student {
    int id;
    char name[MAX_NAME];
    int ten[MAX_TEN];
    double total;
};

struct student all_students[MAX_STUDENT]; // 学生を格納する配列
int student_size = 0;

// 関数のプロトタイプ宣言
int main(void);
int input_all_students(void);
void sort_all_students_by_id(void);
void sort_all_students_by_total(void);
void print_all_students(void);
void print_stat(void);

// 標準入力から学生を読み込み、すべての処理を行う
int main(void)
{
    // 学生を読み込む
    if (input_all_students() < 0) {
        printf("データの読み込みでエラーが起きました\n");
        return -1;
    }

    // 学生数を表示する
    printf("== 学生数 ==\n");
    printf("%d 人\n", student_size);
    printf("\n");

    // 出席番号順で並べ替え、名簿を表示する
    printf("== 出席番号順の名簿 ==\n");
    sort_all_students_by_id();
    print_all_students();
    printf("\n");

    // 合計点順で並べ替え、名簿を表示する
    printf("== 合計点による成績順位表 ==\n");
    sort_all_students_by_total();
    print_all_students();
    printf("\n");

    // 平均点・最高点・最低点を表示する
    printf("== 平均点・最高点・最低点 ==\n");
    print_stat();
    printf("\n");

    return 0;
}

// 標準入力からデータを読み込む関数
// 変数all_students[]とstudent_sizeを更新する。
// 正常終了時は読み込んだ学生数(0以上)を返す
// 異常時は-1を返す
int input_all_students(void)
{
    char buffer[BUFFER_SIZE];
    char name_buffer[BUFFER_SIZE];
    int n = 0; // 学生数

    while ( fgets(buffer, BUFFER_SIZE, stdin) != NULL ) {
        if (n >= MAX_STUDENT) {
            printf("学生数が多すぎます (最大 %d 人)\n", MAX_STUDENT);
            return -1;
        }

        // 読み込んだ学生データを代入する学生へのポインタ
        struct student *sp = &all_students[n];

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
            printf("%d 行目の以下の行で形式が間違っています。\n", n + 1);
            printf("%s\n", buffer);
            return -1;
        }

        // 氏名の長さをチェックしてオーバーフローを防ぐ
        if ( strlen(name_buffer) + 1 > MAX_NAME ) {
            printf("%d 行目にある以下の名前は長すぎます (最大 %d バイト) \n", n + 1, MAX_NAME - 1);
            printf("%s\n", name_buffer);
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
    student_size = n;
    return student_size;
}

// 出席番号順で並べ替えを行う
void sort_all_students_by_id()
{
    for (int i = 0; i < student_size - 1; i++) {
        struct student *sp1 = &all_students[i];
        for (int j = i + 1; j < student_size; j++) {
            struct student *sp2 = &all_students[j];
            if (sp1->id > sp2->id) {
                struct student s = *sp1;
                *sp1 = *sp2;
                *sp2 = s;
            }
        }
    }
}

// 合計点数順で並べ替えを行う。
void sort_all_students_by_total(void)
{
    for (int i = 0; i < student_size - 1; i++) {
        struct student *sp1 = &all_students[i];
        for (int j = i + 1; j < student_size; j++) {
            struct student *sp2 = &all_students[j];
            if (sp1->total < sp2->total) {
                struct student s = *sp1;
                *sp1 = *sp2;
                *sp2 = s;
            }

        }
    }
}

// データを表示する
void print_all_students(void)
{
    for (int n = 0; n < student_size; n++) {
        struct student *sp = &all_students[n];

        // 連番
        printf("%3d) ", n + 1);
        // 点数
        for (int i = 0; i < MAX_TEN; i++) {
            printf("%3d ", sp->ten[i]);
        }
        // 出席番号
        printf("出席番号 %3d ", sp->id);
        // 合計点
        printf("合計点 %0.1f ", sp->total);
        // 平均点
        printf(" %0.1f ", sp->total / MAX_TEN);
        // 氏名
        printf("氏名 %s", sp->name);
        printf("\n");
    }
}

// 教科ごとの平均点・最高点・最低点を計算し、表示する。また合計点の平均も表示する
void print_stat(void)
{
    int max[MAX_TEN];
    int min[MAX_TEN];
    double ten[MAX_TEN];
    double total;
    struct student *sp;

    // 0番目の学生のデータで初期化
    sp = &all_students[0];
    for (int i = 0; i < MAX_TEN; i++) {
        max[i] = sp->ten[i];
        min[i] = sp->ten[i];
        ten[i] = sp->ten[i];
    }

    total = sp->total;

    // 統計計算
    for (int n = 1; n < student_size; n++) {
        sp = &all_students[n];
        for (int i = 0; i < MAX_TEN; i++) {
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
    for (int i = 0; i < MAX_TEN; i++) {
        printf("教科 %d ", i + 1);
        printf("最高点 %3d", max[i]);
        printf("最低点 %3d", min[i]);
        printf("平均点 %0.1f\n", ten[i] / student_size);
    }

    printf("合計点の平均 %0.1f\n", total / student_size);
}
