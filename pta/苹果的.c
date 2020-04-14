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

            case 1://¼��ͼ��
                printf("��¼��ͼ�飬��-1����\n");
                head = CreateBook();
                if( NULL == head )
                    break;
                WriteFile(head);
                printf("���̳ɹ�\n");
                break;
            case 2://����ͼ��
            head=ReadFile();
            if(NULL==head)
            {
                printf("�ļ�Ϊ�գ���Ҫ����¼��ͼ�飡");
            }else{
                AddBook(head);
                WriteFile(head);
                printf("���������̳ɹ���\n");
            }break;
            case 4://��ʾͼ���б�
                head = ReadFile();
                if( NULL == head )
                {
                    printf("�ļ�Ϊ�գ���Ҫ¼��ͼ��\n");
                }else{
                   DisplayBook(head);
				}
				break;
            case 5://����Ų�ѯ
                

            default: break;
        }
		fflush(stdin);
		getchar();
	}
    return 0;
}

void showMainMenu(void)
{
        //��������
		system("cls");
		printf("                             ------------------\n");
		printf("                             *ͼ����Ϣ����ϵͳ*\n");
		printf("                             ------------------\n\n");
		printf("               **********************************************\n\n");
		printf("               **********************************************\n\n");
		printf("               * 1-ͼ��¼��                    2-���ͼ��   *\n\n");
		printf("               * 3-ɾ��ͼ��                    4-ͼ������   *\n\n");
		printf("               * 5-��ѯͼ��                    6-�޸�ͼ��   *\n\n");
		printf("               * 0-�˳�ϵͳ                                 *\n\n");
		printf("               **********************************************\n\n");
		printf("               **********************************************\n\n");
		printf("��������ѡ������:");
}

BOOK *CreateBook(void)
{
    BOOK *head, *tail, *pnew;
	int num; //���
    head = NULL;
    while(1)
    {
        do{
            printf("������ͼ����:");
            scanf("%d",&num);
            if( -1 == num )
                return head;
        }while( Check(head,num) == 1 );
        pnew = (BOOK *)malloc(sizeof(BOOK));
        pnew->num = num;
        printf("����������:");
        scanf("%s",pnew->bname);
        printf("������������:");
        scanf("%s",pnew->wname);
        printf("������۸�:");
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
//���head�����У��Ƿ��нڵ�ı��������num��ͬ
//����ֵ1���У�0����
int Check(BOOK *head, int num)
{
    BOOK *p = head;
    while( p!=NULL)
    {
        if ( p->num == num )
        {
            printf("������ı���ظ�!\n");
            return 1;
        }
        p = p->next;
    }
    if( NULL == p)
        return 0;
}
//������headд���ļ���
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
		printf("����Ϊ�գ��޷���ʾ����\n");
		return;
	}
	printf("                                 ͼ����Ϣ�б�����\n");
	printf("            ==========================================================\n");
	printf("             ���        ͼ����    ������   �۸�\n");
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
        printf("����������ͼ��ı�ţ�");
        scanf("%d",&num);
        if(-1==num)
        {
            printf("������ı����-1���޷�����\n");
            return;
        }
    }while(Check(head,num)==1);
    pnew=(BOOK*)malloc(sizeof(BOOK));
    pnew->num=num;
    printf("����������ͼ���������");
    scanf("%s",pnew->bname);
    printf("����������ͼ�����������");
    scanf("%s",pnew->wname);
    printf("����������ͼ��ļ۸�");
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