#include<stdio.h>
int main()
{
    int x,y,z,a;
    printf("100��1000֮�ڵ�ˮ�ɻ�����:\n");
    for(a=100;a<1000;a++){
    x=a/100;
    y=(a-x*100)/10;
    z=a-x*100-y*10;
    if(a==x*x*x+y*y*y+z*z*z)
    printf("%d\n",a);
    }
    return 0;
}

    