#include <stdio.h>

int main(void);

int main(void)
{
    int ten[] = {65, 90, 75};

    for (int i = 0; i < sizeof(ten) / sizeof(ten[0]); i++) {
        printf("%d ", ten[i]);
    }
    printf("\n");

    printf("%lu\n", sizeof(ten));    // 配列tenがメモリ上で何バイトを占めているかを表す値
    printf("%lu\n", sizeof(ten[1])); // 配列tenの最初の要素がメモリ上で何バイトを占めているかを表す
    printf("%lu\n", sizeof(ten) / sizeof(ten[0])); // 配列全体のバイト数 ÷ 1要素あたりのバイト数

    return 0;
}
