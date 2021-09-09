#include <stdio.h>
#include <ctype.h>

int main(void);
int count_upper(char *string, int *length);

int count_upper(char *string, int *length)
{
    int upper_count = 0;
    int len_count = 0;

    while (*string != '\0') {
        if (isupper(*string)) {
            upper_count++;
        }
        string++;
        len_count++;
    }

    *length = len_count;

    return upper_count;
}

int main(void)
{
    int len;
    int upper = count_upper("This is Japan.", &len);

    printf("len = %d\n", len);
    printf("upper = %d\n", upper);
}
