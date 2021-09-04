#include <stdio.h>
#include <stdlib.h>

int main(void);

int main(void)
{
    char c;

    printf("あなたの好きな飲み物は？\n");
    printf("a コーヒー\n");
    printf("b ミルクティー\n");
    printf("c どちらでもない\n");

    c = getchar();

    switch (c) {
        case 'a': // FALL THROUGH
        case 'A':
            printf("コーヒーです\n");
            break;
        case 'b': // FALL THROUGH
        case 'B':
            printf("ミルクティーです\n");
            break;
        default:
            printf("どちらでもありません\n");
            break;
    }

    return 0;
}
