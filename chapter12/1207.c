#include <stdio.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("使用法: %s OLDFILE NEWFILE\n", argv[0]);
        printf("OLDFILE を NEWFILE に名前変更します。\n");
        return -1;
    }

    if ( rename(argv[1], argv[2]) != 0 ) {
        printf("%s を %s に名前変更できません。\n", argv[1], argv[2]);
        return -1;
    } else {
        printf("%s を %s に名前変更しました。\n", argv[1], argv[2]);
        return 0;
    }
}
