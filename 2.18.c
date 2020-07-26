#include<stdio.h>
void swap( char str[]);
int main()
{
    char a[]="bejing";
    swap(a);
    printf("a=%p\n",a);
    printf("after swap %s\n",a);
}
void swap(char str[])
{
    printf("str=%p\n",str);
    printf("before swap %s\n",str);
    str="wuhan";
    printf("after :%s\n",str);
}