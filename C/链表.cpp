#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef int status;

typedef struct lnode//��������ĳ�ʼ��
{
	elemtype data;
	struct lnode *next;
 } lnode,*linklist;

void createlist(linklist *L,int n)//�����һ����������
{
	linklist p;//��������Ա����͵�p
	*L=(linklist)malloc(sizeof(lnode)); //�ö���ָ��Lָ�������ͷ�ڵ�
	(*L)->next=NULL;
    printf("���������Ա��ֵ\n");
    for(int i=1;i<=n;i++)//����ǰ�巨������������ڵ�
	  {
	    p=(linklist)malloc(sizeof(lnode));//���ǹ���ڵ�
	     scanf("%d",&p->data);
	     p->next=(*L)->next;
	     (*L)->next=p;
	  }
	 printf("��������ֵ\n");   //�����������Ԫ�أ�����ֻ������������������С�

	 for(;p!=NULL;p=p->next)
	  printf("%d\n",p->data);
 }

status listdelete(linklist *L,int i)//���������ɾ��
{
	linklist *p,q;
	int j=0;
	p=L;
	elemtype e;

	while((*p)->next&&j</*=*/i-1)
	{
	   (*p)=(*p)->next;
	   ++j;
	 }

	if(!((*p)->next)/*||j>i-1*/){
        printf("Error\n");
	return 0;
	}

	q=(*p)->next;
	(*p)->next=q->next;
	e=q->data;
	printf("ɾ����ֵΪ��%d\n",e);
	free(q);

	//*L=(linklist)malloc(sizeof(lnode));
	linklist a = *L;
	//(*L)->next=NULL;
	//(*L)->next=a;

	printf("��������ֵ��\n");
	for(;a!=NULL;a=a->next)
	printf("%d\n",a->data);

	return 1;
}

status listinsert(linklist *L,int i,int e)
{
	linklist p,s;
	p=*L;
	int j = 0;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}

	if(!p/*||j>i-1*/)
	return 0;

	s=(linklist)malloc(sizeof(lnode));
	s->data=e;
	s->next=p->next;
	p->next=s;

	//*L=(linklist)malloc(sizeof(lnode));
	//(*L)->next=NULL;
	linklist a = *L;
	//(*L)->next=a;

   	printf("��������ֵ��\n");
	for(;a!=NULL;a=a->next)
	printf("%d\n",a->data);

	return 1;
}

main()
{

	linklist L;
    int n;
	printf("������������������ĳ���Ϊ:\n");
	scanf("%d",&n);
    createlist(&L,n);

	int m;
	printf("����ɾ��Ԫ�ص�λ��:\n");
    scanf("%d",&m);
    listdelete(&L,m);

    int a,b;
    printf("�������Ԫ�ص�λ�ú�ֵ:\n");
    scanf("%d%d",&a,&b);
    listinsert(&L,a,b);

}
