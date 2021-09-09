#include <stdio.h>  // NULLはstdio.hで定義されている

char *scan_char(char *p, char c);
void test_scan_char(char *str, char c);
int main(void);

char *scan_char(char *p, char c)
{
    while (*p != '\0') {
        if (*p == c) {
            return p;
        }
        p++;
    }

    return NULL;
}

void test_scan_char(char *str, char c)
{
    char *s = scan_char(str, c);

    if (s == NULL) {
        printf("\"%s\" の中に '%c' は見つかりません。\n", str, c);
    } else {
        printf("\"%s\" の中に '%c' は見つかりました。\n", str, c);
        printf("見つかった場所以降の文字列は \"%s\" です。\n", s);
    }
}

int main(void)
{
    test_scan_char("This is Japan.", 'J');
    test_scan_char("This is Japan.", 'E');

    return 0;
}
