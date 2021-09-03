#include <stdio.h>

int main(void);

int main(void)
{
    printf("%f\n", 12.34);     // 普通に表示
    printf("%6f\n", 12.34);    // 少なくとも6桁で表示
    printf("%6.0f\n", 12.34);  // 少なくとも6桁で、小数部は表示せず
    printf("%6.1f\n", 12.34);  // 少なくとも6桁で、少数第一位まで表示
    printf("%0.1f\n", 12.34);  // 桁を気にせず少数第一位まで表示
    return 0;

}
