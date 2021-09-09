#include <stdio.h>

int main(void);
char *scan_char(char *p, char s);

char *scan_char(char *p, char s)
{
    char *str = p;

    while (*str != '\0') {
        if (*str == s) {
            return str;
        }
        str++;
    }

    return NULL;
}

int main(void)
{
    char *q;
    q = scan_char("This is Japan.", 'J');
    printf("%s\n", q);

    q = scan_char("This is Japan.", 'E');
    printf("%s\n", q);

    return 0;
}
