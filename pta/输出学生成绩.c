#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    double *p,sum=0,ave;
    scanf("%d",&n);
    p=(double*)malloc(n*sizeof(double));
    for(i=0;i<n;i++)
    {
        scanf("%lf",p+i);
        sum+=*(p+i);
    }
    double min=*p,max=*p;
    for(i=1;i<n;i++)
    {
        if(*(p+i)>max)max=*(p+i);
        if(*(p+i)<min)min=*(p+i);
    }
    free(p);
    ave=sum/n;
    printf("average =%.2lf\n",ave);
    printf("max = %.2lf\n",max);
    printf("min = %.2f\n",min);
}