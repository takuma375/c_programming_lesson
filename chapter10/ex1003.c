#include <stdio.h>
#include <math.h>

// 長方形を表す構造体
struct rectangle {
    double x1, y1; // 左上の点
    double x2, y2; // 右下の点
};

int main(void);
double distance(double a, double b);
double calc_area(struct rectangle r);

int main(void)
{
    struct rectangle rect;
    double area;

    rect.x1 = 3.1;
    rect.y1 = 4.1;
    rect.x2 = 5.9;
    rect.y2 = 2.6;
    area = calc_area(rect);
    printf("長方形 (%g, %g)-(%g, %g) の面積は、 %g です。\n",
            rect.x1, rect.y1, rect.x2, rect.y2, area);
}

// 関数 distance は差の絶対値を求める
double distance(double a, double b)
{
    if (a > b) {
        return a - b;
    } else {
        return b - a;
    }
}


// 関数 calc_area は与えられた長方形の面積を計算する
double calc_area(struct rectangle r)
{
    double x, y; // 2辺の長さ
    x = distance(r.x1, r.x2);
    y = distance(r.y1, r.y2);

    return x * y;
}
