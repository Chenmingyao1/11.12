#include<stdio.h>
char *mystrcat(char *des,char*src)
{
    char *temp=des;
    while(*temp++!='\0');
    temp--;
    while((*temp++=*src++)!='\0');
    return des;
}
int main()
{
    char str[15]="jzszdm";
    char str1[6]="drszd";
    char *p=mystrcat(str,str1);
    printf("p=%s",p);
    getchar();
    return 0;

}