#include <stdio.h>
#include <stdarg.h>
#include "normal.c"

/*void hello(int x)
{
    void hi()
    {
        printf("%d", x * x);
    }
    hi();
}*/

/*int hi(int n)
{
    return n * n;
}
void hello(int n, int (*p)(int))
{
    int x = p(n);
    printf("%d", x);
}*/

/*int *hello(int x)
{
    int hi()
    {
        return x * x;
    }
    return hi;
}*/

/*void hello(int count, ...)
{
    va_list list;
    double sum = 0;
    va_start(list, count);
    for (int i = 1; i <= count; i++)
    {
        sum = sum + va_arg(list, int);
    }
    printf("%lf", sum);
    va_end(list);
}*/

int main()
{
    /*int a = 0;
school:
    printf("A");
    a++;
    if (a < 3)
        goto school;
    else
        goto college;
    printf("B");
college:
    printf("C");
    printf("D");*/

    /*printf("A"
           "B\n");
    printf("A", "B");*/

    /*auto void hello();
    hello();
    void hello()
    {
        printf("Hello");
    }*/

    /*extern int a;
    printf("%d", a);*/

    // printf("%c", 36 + 24);

    /*int a = 5, b = 6, c;
    c = ++a + ++b + a++ + b++;
    printf("%d %d %d", a, b, c);*/

    /*int a = 5, b = 6;
    printf("%d\t%d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("%d\t%d", a, b);*/

    /*int *p;
    printf("%d", sizeof(p));*/

    /*unsigned int a = 10;
    signed int b = -10;
    printf("%u", b < a);*/

    /*int a = 65;
    switch (a)
    {
    case 1:
        printf("A");
        break;
    case 3:
        printf("B");
        break;
    case 'A':
        printf("C");
        break;
    default:
        printf("D");
    }*/

    /*int a = 5;
    const int b = 6;
    int *p;
    const int *q;
    q = &a;
    a = 10;
    printf("%d", a);*/

    /*int a = 0X110;
    long long unsigned a = 987654345;
    printf("%ull", 876578876llu);
    printf("%llu", sizeof(long long int));*/

    /*char *p = "Hello";
    char q[] = "Hello";
    //p[2] = 'z';
    q[2] = 'z';
    printf("%s\t", p);
    printf("%s", q);*/

    // hello(5, hi);

    /*int (*p)() = hello(5);
    printf("%d", p());*/

    // hello(5, 1, 2, 3, 4, 5);

    /*int a = 100;
    int b = printf("a=%d", a);
    printf("%d", b);*/

    /*int a, b, c;
    a = scanf("%dx%d", &b, &c);
    printf("%d", a);*/

    return 0;
}