#include <stdio.h>

int perimeter(int a, int b)
{
    int p=(a+b)*2;
    return p;
}

int ploshad(int a, int b)
{
    int s=a*b;
    return s;
}

int main()
{
    int perimeter(int a,int b);
    int ploshad(int a,int b);
    int a,b,p,s;
    printf("\nEnter length ");
    scanf("%d", &a);
    printf("\nEnter width ");
    scanf("%d", &b);
    p=perimeter(a,b);
    s=ploshad(a,b);
    printf("\nPerimeter and area are %d %d",p,s);
}
