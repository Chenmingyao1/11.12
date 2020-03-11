#include<stdio.h>
#include<string.h>
struct lianxire 
{
    char name[20];
    int birthday;
    char  number[15];
};
struct birthday
{
    int year;
    int mouth;
    int day;
};

int main()
{
    int i,j,n;
    printf("please input people num:\n");
    scanf("%d",&n);
    struct lianxire stu[100];
    struct birthday info[100];
    for(i=0;i<n;i++)
    {
        printf("please input %d name:\n",i);
        scanf("%s",stu[i].name);
        printf("pleasr input %d birthday:\n",i);
        scanf("%d",&stu[i].birthday);
        printf("please input %d phone number:\n",i);
        scanf("%s",stu[i].number);
        info[i].year=stu[i].birthday/10000;
        info[i].mouth=stu[i].birthday/100-info[i].year*100;
        info[i].day=stu[i].birthday%100;
    }
    for(i=0;i<n;i++)
    {
        
        int strcmp(const char *s1,const char *s2);
         
        for(j=0;j<n-i-1;j++){
        
        if(strcmp(stu[j].name,stu[j+1].name)>0)
        {
           struct lianxire tmp;
           tmp=stu[j];
           stu[j]=stu[j+1];
           stu[j+1]=tmp;
        }
        }
    }
        for(i=0;i<n;i++)
        {
            if(info[i].mouth>=10&&info[i].day>=10)
        {
            printf("name=%s,birthday=%d/%d/%d,phone=%s\n",stu[i].name,info[i].year,info[i].mouth,info[i].day,stu[i].number);
        }else if(info[i].mouth>=10&&info[i].day<10)
        {
            printf("name=%s,birthday=%d/%d/0%d,phone=%s\n",stu[i].name,info[i].year,info[i].mouth,info[i].day,stu[i].number);
        }else if(info[i].mouth<10&&info[i].day>10)
        {
            printf("name=%s,birthday=%d/0%d/%d,phone=%s\n",stu[i].name,info[i].year,info[i].mouth,info[i].day,stu[i].number);
        }else if(info[i].mouth<10&&info[i].day<10)
        {
            printf("name=%s,birthday=%d/0%d/0%d,phone=%s\n",stu[i].name,info[i].year,info[i].mouth,info[i].day,stu[i].number);

        }}
} 

    

