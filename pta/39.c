#include<stdio.h>
struct Stu_Info
{
      char no[10];
      char name[20];
      float chinese;
      float math;
      float english;
    
};
int main()
{
    float sum=0,ave=0;
    struct Stu_Info stu;
    printf("please input student no:");
    scanf("%s",stu.no);
    scanf("%s",stu.name);
    scanf("%f",&stu.chinese);
    scanf("%f",&stu.math);
    scanf("%f",&stu.english);
    sum=stu.chinese+stu.math+stu.english;
    ave=sum/3;
    printf("sum=%f,ave=%f\n",sum,ave);
    return 0;
}