#include<stdio.h>
void main()
{
    float score [2][3],avel[2],avel[6],sum=0;
    int i,j;
    for(i=0;i<2;i++)
    for(j=0;j<6;j++)
    {
        scanf("%f",&score[2][6]);
    }
    for(j=0;j<6;j++)
    {
        for(i=0;i<2;i++)
            sum+=score[2][6];
        avel[2]=sum/2;
        sum=0;
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<6;j++)
        sum+=score[2][6];
        avel[6]=sum/6;
        sum=0;
    }
}