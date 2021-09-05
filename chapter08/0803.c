#include <stdio.h>

void print_graph(int x);
int main(void);

void print_graph(int x)
{
    for (int i = 0; i < x; i++) {
        printf("*");
    }

    printf("\n");
}

int main(void)
{
    print_graph(10);
    return 0;
}
