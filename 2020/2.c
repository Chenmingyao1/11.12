#include<stdio.h>
int fun(int a[])
{
    int i,j,t;
    for(i=0;i<9;i++)
    for(j=0;j<9-i;j++)
    {
        if(a[j]<a[j+1]){
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }

    }return a[1];
}
int main()
{
    int a[10],i,m;
    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    m=fun(a);
    printf("%d",m);

}