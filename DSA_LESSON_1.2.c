#include <stdio.h>

//pointer reference example
int main()
{
    int a;

    printf("Enter Variable: ");
    scanf("%d", &a);

    int *p;
    int **q, **r;
    int ***s, ***t, ***u, ***v;

    p = &a;
    q = &p;
    r = &p;
    s = &q;
    t = &q;
    u = &r;
    v = &r;

    printf("%d\n", *p);
    printf("%d\n", **q);
    printf("%d\n", **r);
    printf("%d\n", ***s);
    printf("%d\n", ***t);
    printf("%d\n", ***u);
    printf("%d\n", ***v);
    printf("%d\n", a);
}
