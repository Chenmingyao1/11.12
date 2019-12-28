#include<stdio.h>
int station(int a[],int n)
{
    int i,k;
    k=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]>a[k])
        k=i;}
        return(k+1);
    
}
main()
{
    int a[100],n,i,t;
    printf("enter n:\n");
    scanf("%d",&n);
    printf("\n");
    printf("enter the array:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    t=station(a,n);
    printf("the max_value position is:%d\n",t);
}
