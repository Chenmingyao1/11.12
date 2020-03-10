#include<stdio.h>
struct Stu_Info
{
    char no[10];
    char name[20];
    float Chinese;
    float math;
    float english;
    float ave;
};
typedef struct Stu_Info STU;
int main()
{
    int i,n,j;
    STU stu[10];
    float sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
{
    printf("please input student no:");
    scanf("%s",stu[i].no);
    scanf("%s",stu[i].name);
    scanf("%f",&stu[i].Chinese);
    scanf("%f",&stu[i].math);
    scanf("%f",&stu[i].english);
    sum=stu[i].math+stu[i].Chinese+stu[i].english;
    stu[i].ave=sum/3;
}
for(i=0;i<n-1;i++)
{
    
    for(j=0;j<n-i-1;j++)
    {
        if(stu[j].ave>stu[j+1].ave)
        {
          STU tmp;
        tmp=stu[j];
        stu[j]=stu[j+1];
        stu[j+1]=tmp;}
    
    }
}
for(i=0;i<n;i++)
{
    printf("name=%s,ave=%.lf\n",stu[i].name,stu[i].ave);
}
}