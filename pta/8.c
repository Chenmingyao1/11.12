#include<stdio.h>
#include<string.h>
struct telph
{
    char name[10],birth[8],phnum[20];
};
void line (struct telph *p,int n);
int main()
{
  int i,j,n;
  struct telph tel[10];
  printf("please input people num :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
      printf("please input %d people name: ",i+1);
      scanf("%s",&tel[i].name);
      printf("please input %d people birthday:yyyymmdd",i+1);
      scanf("%s",&tel[i].birth);
      printf("please input %d phone number :",i+1);
      scanf("%s",&tel[i].phnum);
  }
  line(tel,n);
  for(i=0;i<n;i++)
  {
      printf("name=%s,phone=%s,birthday=",tel[i].name,tel[i].phnum);
      for(j=0;j<8;j++)
      {
          if((j==4||j==6))
          printf("/");
          printf("%c",tel[i].birth[j]);
      }printf("\n");
  }
  return 0;
}
void line(struct telph *p,int n)
{
    int i,j;
    struct telph temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp((p+j)->name,(p+j+1)->name)>0)
            {
                    temp=*(p+j);
                    *(p+j)=*(p+j+1);
                    *(p+j+1)=temp;
            }
        }
    }
}