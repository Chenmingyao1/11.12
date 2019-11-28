#include<stdio.h>
int main()
{
    int x,y,z,a;
    printf("100到1000之内的水仙花数有:\n");
    for(a=100;a<1000;a++){
    x=a/100;
    y=(a-x*100)/10;
    z=a-x*100-y*10;
    if(a==x*x*x+y*y*y+z*z*z)
    printf("%d\n",a);
    }
    return 0;
}

    