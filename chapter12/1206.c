#include <stdio.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("使用法: %s FILE\n", argv[0]);
        printf("FILE を削除します。\n");
        return -1;
    }

    if ( remove(argv[1]) != 0 ) {
        printf("%s は削除できません。\n", argv[1]);
        return -1;
    } else {
        printf("%s を削除しました。\n", argv[1]);
        return 0;
    }

}
