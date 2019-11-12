#include<stdio.h>
int main()
{
    int choice,i;
    double price;
    for (i=1;i<=5;i++)
    {
        printf("[1]select apples\n");
        printf("[2]select pears\n");
        printf("[3]select oranges\n");
        printf("[4]select grapes\n");
        printf("[0]exit\n");

        printf("enter choice:");
        scanf("%d",&choice);
        if (choice==0)
            break;
        switch (choice)
        {
        case 1:price=3.0;break;
        case 2:price=2.5;break;
        case 3:price=4.1;break;
        case 4:price=10.2;break;
        default:
            break;
        }
            printf("price=%0.1f\n",price);
    }
    printf("Thanks\n");
    return 0;
}
