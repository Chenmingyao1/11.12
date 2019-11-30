#include<stdio.h>
#include<math.h>
int isPrime(int x)
{
    int  i;
    for(i=2;i<=sqrt(x);i++)
    {
        if(x%i==0){
        
        return 0;
        break;
        }
        
        
    }
    if(i>sqrt(x))
        return 1;


}
int main(void)
{
    int x,count=0;
    for(x=2;x<=100;x++)
    {
        if (isPrime(x)==1){
            printf("%5d",x);
            count++;
        }
        if (count%10==0)
        printf("\n");
    }
    printf("\n");
    return 0;
}