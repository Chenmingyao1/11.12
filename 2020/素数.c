#include<stdio.h>
#include<math.h>
int isPrime(int x)
{
    int i;
    if(x==1)
    return 0;
    for(i=2;i<=sqrt(x);i++)
    {
        if(x%i==0){
            
            return 0;
        }
    return 1;}
}
int main()
{
    int count=0,m;
    for(m=2;m<=100;m++)
    {
        if(isPrime(m)!=0)
        {
            printf("%6d",m);
            count++;
        }
        if (count%10==0)  printf("\n");
    }printf("\n");
    return 0;
}