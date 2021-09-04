// 整数で表すことのできる範囲を表示する

#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("%22s 型は %d 以上 %d 以下\n",
            "char",
            CHAR_MIN,
            CHAR_MAX);

    printf("%22s 型は %d 以上 %d 以下\n",
            "signed char",
            SCHAR_MIN,
            SCHAR_MAX);

    printf("%22s 型は %u 以上 %u 以下\n",
            "unsigned char",
            0,
            UCHAR_MAX);

    printf("%22s 型は %d 以上 %d 以下\n",
            "short int",
            SHRT_MIN,
            SHRT_MAX);

    printf("%22s 型は %d 以上 %d 以下\n",
            "unsigned short int",
            0,
            USHRT_MAX);

    printf("%22s 型は %d 以上 %d 以下\n",
            "int",
            INT_MIN,
            INT_MAX);

    printf("%22s 型は %u 以上 %u 以下\n",
            "unsigned int",
            0,
            UINT_MAX);

    printf("%22s 型は %ld 以上 %ld 以下\n",
            "long int",
            LONG_MIN,
            LONG_MAX);

    printf("%22s 型は %lu 以上 %lu 以下\n",
            "unsigned long int",
            0UL,
            ULONG_MAX);

    printf("%22s 型は %lld 以上 %lld 以下\n",
            "long long int",
            LLONG_MIN,
            LLONG_MAX);

    printf("%22s 型は %llu 以上 %llu 以下\n",
            "unsigned long long int",
            0ULL,
            ULLONG_MAX);

    return 0;

}
