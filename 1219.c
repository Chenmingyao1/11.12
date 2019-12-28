#include<stdio.h>
long int fun(int n)
{
    int i=1,sum=0;
    do{
        sum=sum+i;
        i++;
    }while(i<=n);
    return sum;
}
void main()
{
    int i=100;
    printf("sum is:%ld\n",fun(i));
}