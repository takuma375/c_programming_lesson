#include <stdio.h>

#define KAMOKU 5
#define SEITO 3

int main(void);

int main(void)
{
    int tens[SEITO][KAMOKU] = {
        { 64, 90, 75, 45, 80 },
        { 85, 100, 95, 82, 90 },
        {100, 100, 100, 100, 99},
    };

    for (int i = 0; i < SEITO; i++) {
        int sum = 0;
        for (int j = 0; j < KAMOKU; j++) {
            printf("%3d ", tens[i][j]);
            sum += tens[i][j];
        }
        printf("→ ");
        printf("%3d ", sum);
        printf("%0.1f\n", (double)sum / KAMOKU);
    }

    return 0;
}
