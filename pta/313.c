#include<stdio.h>
#include<string.h>
struct birthday
{

    char year[5];
    char mouth[3];
    char day[3];
};
struct a
{
     char name[10];
     struct birthday b;
     char phnum[12];
};
int main()
{

    int i,j,n;
    struct  a a[10],temp;
    char stu[9];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
          printf("please input %d name:",i+1);
          scanf("%s",a[i].name);
          printf("please input %d birthday: ",i+1);
          scanf("%s",stu);
          for(j=0;j<4;j++)
          {
              a[i].b.year[j]=stu[j];

          }a[i].b.year[4]='\0';

          for(j=0;j<2;j++)
          {

              a[i].b.mouth[j]=stu[j+4];
          }a[i].b.mouth[2]='\0';
          for(j=0;j<2;j++)
          {

              a[i].b.day[j]=stu[j+6];
          }a[i].b.day[2]='\0';
          getchar();
          printf("please input %d phone number :",i+1);
          scanf("%s",a[i].phnum);
          }

          for(i=0;i<n;i++)
          {

              for(j=0;j<n-i-1;j++)
              {

                  if(strcmp(a[j].name,a[j].name)>0)
                  {

                      temp=a[j];
                      a[j]=a[j+1];
                      a[j+1]=temp;

                  }
              }

          }
          for(i=0;i<n;i++)
          {

              printf("name =%s,birthday=%s/%s/%s,phone number=%s",a[i].name,a[i].b.year,a[i].b.mouth,a[i].b.day,a[i].phnum);
          }
          return 0;

        }















