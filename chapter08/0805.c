#include <stdio.h>
#include <stdlib.h>

#include "get_line.h"

#define BUFFER_SIZE 256

int main(void);

int main(void)
{
    char buffer[BUFFER_SIZE];

    printf("あなたの名前を入力してください。\n");
    get_line(buffer, BUFFER_SIZE);
    printf("%s さん、こんにちは。\n", buffer);

    return 0;
}
