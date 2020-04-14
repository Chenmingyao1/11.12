#include <stdio.h>
#include<stdlib.h>
#define FILENAME "books.dat"
struct book{
	int num;
	char bname[50];
	char wname[20];
	float price;
    struct book *next;
};
typedef struct book BOOK;
void showMainMenu(void);
BOOK *CreateBook(void);
void WriteFile(BOOK *head);
int Check(BOOK *head, int num);
BOOK *ReadFile(void);
void AddBook(BOOK *head);
void DisplayBook(BOOK *head);
void FindbyNum(BOOK *head);


int main(void)
{
    int choice, x=1;
    BOOK *head;

    while( x!=0 )
    {
        showMainMenu();
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
            case  0:
                x=0;
                break;

            case 1://录入图书
                printf("请录入图书，以-1结束\n");
                head = CreateBook();
                if( NULL == head )
                    break;
                WriteFile(head);
                printf("存盘成功\n");
                break;
            case 2://增加图书
            head=ReadFile();
            if(NULL==head)
            {
                printf("文件为空，需要重新录入图书！");
            }else{
                AddBook(head);
                WriteFile(head);
                printf("新增：存盘成功！\n");
            }break;
            case 4://显示图书列表
                head = ReadFile();
                if( NULL == head )
                {
                    printf("文件为空，需要录入图书\n");
                }else{
                   DisplayBook(head);
				}
				break;
            case 5://按编号查询
                

            default: break;
        }
		fflush(stdin);
		getchar();
	}
    return 0;
}

void showMainMenu(void)
{
        //清屏函数
		system("cls");
		printf("                             ------------------\n");
		printf("                             *图书信息管理系统*\n");
		printf("                             ------------------\n\n");
		printf("               **********************************************\n\n");
		printf("               **********************************************\n\n");
		printf("               * 1-图书录入                    2-添加图书   *\n\n");
		printf("               * 3-删除图书                    4-图书排序   *\n\n");
		printf("               * 5-查询图书                    6-修改图书   *\n\n");
		printf("               * 0-退出系统                                 *\n\n");
		printf("               **********************************************\n\n");
		printf("               **********************************************\n\n");
		printf("请输入所选择的序号:");
}

BOOK *CreateBook(void)
{
    BOOK *head, *tail, *pnew;
	int num; //编号
    head = NULL;
    while(1)
    {
        do{
            printf("请输入图书编号:");
            scanf("%d",&num);
            if( -1 == num )
                return head;
        }while( Check(head,num) == 1 );
        pnew = (BOOK *)malloc(sizeof(BOOK));
        pnew->num = num;
        printf("请输入书名:");
        scanf("%s",pnew->bname);
        printf("请输入作者名:");
        scanf("%s",pnew->wname);
        printf("请输入价格:");
        scanf("%f",&pnew->price);
        pnew->next = NULL;
        if( NULL == head)
            head = pnew;
        else
            tail->next = pnew;
        tail = pnew;
    }
    return head;
}
//检测head链表中，是否有节点的编号与输入num相同
//返回值1：有，0：无
int Check(BOOK *head, int num)
{
    BOOK *p = head;
    while( p!=NULL)
    {
        if ( p->num == num )
        {
            printf("您输入的编号重复!\n");
            return 1;
        }
        p = p->next;
    }
    if( NULL == p)
        return 0;
}
//将链表head写入文件中
void WriteFile(BOOK *head)
{
    FILE *fp;
    BOOK *p;
    fp = fopen( FILENAME, "wb" );
    if( NULL == fp )
    {
        printf("WriteFile fopen fail\n");
        return;
    }
    p = head;
    while(p!=NULL)
    {
        fwrite(p,sizeof(BOOK),1,fp);
        p=p->next;
    }
    fclose(fp);
    return;
}
BOOK *ReadFile(void)
{
	BOOK *head=NULL,*tail,*p;
	FILE *fp;
	fp=fopen(FILENAME,"rb");
	if(fp==NULL)
	{
		printf("fail to open file!\n");
		return NULL;
	}
	while(!feof(fp))
	{
		p=(BOOK*)malloc(sizeof(BOOK));
		if(fread(p,sizeof(BOOK),1,fp)>0)
		{
			p->next=NULL;
			if(head==NULL)
				head=p;
			else
				tail->next=p;
			tail=p;
		}
		else
		{
			free(p);
		}
	}
	fclose(fp);
	return head;
}
void DisplayBook(BOOK *head)
{
	BOOK *p=head;
	if(head==NULL)
	{
		printf("链表为空，无法显示链表\n");
		return;
	}
	printf("                                 图书信息列表如下\n");
	printf("            ==========================================================\n");
	printf("             编号        图书名    作者名   价格\n");
    while(p!=NULL)
	{
		printf("\t%10d%10s%10s%10.2f\n",p->num,p->bname,p->wname,p->price);
		p=p->next;
	}
	printf("            ==========================================================\n");
    return;  
}
void AddBook(BOOK *head)
{
    int num;
    BOOK *pnew,*tail;
    do{
        printf("请输入新增图书的编号：");
        scanf("%d",&num);
        if(-1==num)
        {
            printf("您输入的编号是-1，无法新增\n");
            return;
        }
    }while(Check(head,num)==1);
    pnew=(BOOK*)malloc(sizeof(BOOK));
    pnew->num=num;
    printf("请输入新增图书的书名：");
    scanf("%s",pnew->bname);
    printf("请输入新增图书的作者名：");
    scanf("%s",pnew->wname);
    printf("请输入新增图书的价格：");
    scanf("%f",&pnew->price);
    pnew->next=NULL;
	tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=pnew;
	return;
}
void FindbyNum(BOOK *head)
{
     BOOK *p=head;
     int num;
     scanf("%d",&num);
     if(p->num==num)
     {
        return ;
     }


}