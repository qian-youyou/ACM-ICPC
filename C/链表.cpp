#include<stdio.h>
#include<stdlib.h>

typedef int elemtype;
typedef int status;

typedef struct lnode//线性链表的初始化
{
	elemtype data;
	struct lnode *next;
 } lnode,*linklist;

void createlist(linklist *L,int n)//构造出一个线性链表
{
	linklist p;//构造出线性表类型的p
	*L=(linklist)malloc(sizeof(lnode)); //让二级指针L指向链表的头节点
	(*L)->next=NULL;
    printf("请输入线性表的值\n");
    for(int i=1;i<=n;i++)//采用前插法进行连接链表节点
	  {
	    p=(linklist)malloc(sizeof(lnode));//这是构造节点
	     scanf("%d",&p->data);
	     p->next=(*L)->next;
	     (*L)->next=p;
	  }
	 printf("输出链表的值\n");   //这是输出链表元素，但是只能在这个函数里面运行。

	 for(;p!=NULL;p=p->next)
	  printf("%d\n",p->data);
 }

status listdelete(linklist *L,int i)//线性链表的删除
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
	printf("删除的值为：%d\n",e);
	free(q);

	//*L=(linklist)malloc(sizeof(lnode));
	linklist a = *L;
	//(*L)->next=NULL;
	//(*L)->next=a;

	printf("输出链表的值：\n");
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

   	printf("输出链表的值：\n");
	for(;a!=NULL;a=a->next)
	printf("%d\n",a->data);

	return 1;
}

main()
{

	linklist L;
    int n;
	printf("请输入你想做的链表的长度为:\n");
	scanf("%d",&n);
    createlist(&L,n);

	int m;
	printf("你想删除元素的位置:\n");
    scanf("%d",&m);
    listdelete(&L,m);

    int a,b;
    printf("你想插入元素的位置和值:\n");
    scanf("%d%d",&a,&b);
    listinsert(&L,a,b);

}
