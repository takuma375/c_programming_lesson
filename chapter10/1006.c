// 点・線分・長方形を表示する
// 点を表す構造体
struct point {
    double x;
    double y;
};

// 線分を表す構造体
struct line1 {
    double x1;
    double y1;
    double x2;
    double y2;
};

// 線分を表す構造体2
struct line2 {
    struct point start; // 始点
    struct point end;   // 終点
};

// 長方形を表す構造体1
struct rectangle1 {
    double x1;
    double y1;
    double x2;
    double y2;
};

// 長方形を表す構造体2
struct rectange2 {
    struct point p1;
    struct point p2;
};
