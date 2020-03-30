#include<stdio.h>
#include<stdlib.h>
struct Stu
{
    int score;
    struct Stu *next;
};
typedef struct Stu NODE;
NODE *Create_LinkList()
{
    NODE *head,*tail,*pnew;
    int score;
    head=(NODE*)malloc(sizeof(NODE));
    if(head==NULL)
    {
        printf("no enough memory!\n");
        return (NULL);
    }
    head->next=NULL;
    tail=head;
    printf("input students' scores:\n");
    while(1)
    {
        scanf("%d",&score);
        if(score<0)
            break;
            pnew=(NODE*)malloc(sizeof(NODE));
            if(pnew==NULL)
            {
                printf("no enough memory!\n");
                return (NULL);
            }
        pnew->score=score;
        pnew->next=NULL;
        tail->next=pnew;
        tail=pnew;
    }
    return (head) ;
}
void Insert_LinkList(NODE*head,NODE*pnew,int i)
{
    NODE *p;
    int j;
    p=head;
    for(j=0;j<i&&p!=NULL;j++)
    p=p->next;
    if(p==NULL)
    {
        printf("the %d node not foundt!\n",i);
        return ;
    }
    pnew->next=p->next;
    p->next=pnew;
}
void Delete_LinkList(NODE*head,int i)
{
    NODE *p,*q;
    int j;
    if(i==0)
    return;
    p=head;
    for(j=1;j<i&&p->next!=NULL;j++)
    p=p->next;
    if(p->next==NULL)
    {
        printf("the %d node not foundt!\n",i);
        return ;
    }
    q=p->next;
    p->next=q->next;
    free(q);
}
void Display_LinkList(NODE*head)
{
    NODE*p;
    for(p=head->next;p!=NULL;p=p->next)
    printf("%d ",p->score);
}
void Free_LinkList(NODE*head)
{
    NODE *p,*q;
    p=head;
    while(p->next!=NULL)
    {
        q=p->next;
        p->next=q->next;
        free(q);
    }
    free(head) ;
}
NODE *Search_LinkList(NODE*head,int score)
{
    NODE *p;
    p=head;
    while(p!=NULL)
    {
        if(p->score==score)
        break;
        else
        {
            p=p->next;
        }
        
    }return p;
}
int Update_LinkList(NODE*head,int oldscore,int newscore)
{
    NODE*p=NULL;
    p=Search_LinkList(head,oldscore);
    if(NULL==p)
    {
        printf("sorry,no found!\n");
        return 0;
    }
    p->score=newscore;
    printf("update successfully!\n");
    return 1;
}

void main()
{
    NODE*head,*pnew;
    int chazhao;
    NODE*p;
    head=Create_LinkList();
    if(head==NULL)
    return;
    printf("after create:\n");
    Display_LinkList(head);
    pnew=(NODE*)malloc(sizeof(NODE));
    if(pnew==NULL)
    {
        printf("no enough memory!\n");
        return ;
    }
    pnew->score=88;
    Insert_LinkList(head,pnew,3);
    printf("after insert:");
    Display_LinkList(head);
    Delete_LinkList(head,3);
    printf("after delete:");
    Display_LinkList(head);
    p=Search_LinkList(head,65);
    
    Update_LinkList(head,65,99);

Display_LinkList(head);
    
    Free_LinkList(head);
    
}
