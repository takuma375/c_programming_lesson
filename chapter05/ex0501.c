#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main(void);
void get_line(char *buffer, int size);

int main(void)
{
    char buffer[BUFFER_SIZE];
    int n;

    printf("曜日を0 〜 6の範囲で入力してください。\n");
    get_line(buffer, BUFFER_SIZE);
    n = atoi(buffer);

    switch (n) {
        case 0:
            printf("日曜日\n");
            break;
        case 1:
            printf("月曜日\n");
            break;
        case 2:
            printf("火曜日\n");
            break;
        case 3:
            printf("水曜日\n");
            break;
        case 4:
            printf("木曜日\n");
            break;
        case 5:
            printf("金曜日\n");
            break;
        case 6:
            printf("土曜日\n");
            break;
        default:
            printf("0 〜 6の範囲で入力してください。\n");
            break;
    }

    return 0;

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
