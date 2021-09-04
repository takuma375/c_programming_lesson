#include <stdio.h>
#include <ctype.h>

int main(void);

int main(void)
{
    int uppercase = 0;
    int lowercase = 0;
    int alphabet = 0;
    int space = 0;
    char c;

    while ( (c = getchar()) != EOF ) {
        if (isupper(c)) {
            uppercase++;
        }

        if (islower(c)) {
            lowercase++;
        }

        if(isalpha(c)) {
            alphabet++;
        }

        if(isspace(c)) {
            space++;
        }
    }

    printf("uppercase: %d\n", uppercase);
    printf("lowercase: %d\n", lowercase);
    printf("alphabet: %d\n", alphabet);
    printf("space: %d\n", space);

    return 0;

}
