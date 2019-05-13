/**********************************************************
 Author: Chaoyang Liu
 E-mail: chaoyanglius@outlook.com or chaoyanglius@gmail.com
 date:   May 1st, 2016
 **********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>

#define getpch(type) (type*)malloc(sizeof(type))
/*����״̬*/
#define READY 0
#define RUNNING 1
#define BLOCK -1
//ʱ��Ƭ��С
#define TIME_SLICE 2
//����һ��pcb�ṹ��
typedef struct pcb
{
    char name[10];
    int state;     //����״̬
    int priority;   //���ȼ�
    int reqtime;
    int runtime;
    struct pcb* link;
} PCB;
char message[] = "This is another thread.";
static PCB *ready, *ptr;

/*****************************************************************************/
//�������ȼ��Խ��̽�������
void sort();
//�����̼����������
void join();
//������̶��еĳ���
int length();
//�����̼�����У����������ȼ�����
void input1();
void input2();
//��ý��̵���ϸ��Ϣ
void get_info(PCB *p);
//���н��̵���,���÷���ռ�ľ�̬���ȼ������㷨
void execute1();
//������ת�����㷨
void execute2();
//��ʾ���̵���ϸ��Ϣ
void *display(void *arg);
//����ִ�н��������ٽ���
void destory(PCB *p);
/*****************************************************************************/

int main()
{
    pthread_t disp_thread;
    void *dis_result;
    int a;
    printf("----------------------command---------------------\n");
    printf("1: static priority-driven nonpreemptive scheduling\n");
    printf("2: round robin scheduling\n");
    printf("--------------------------------------------------\n");
    printf("Please enter your commmand: ");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        //������̵���ϸ��Ϣ
        input1();
        //��������
        system("CLS");
        //������һ���������ڼ��ӽ��̵��ȵ���ϸ��Ϣ
        pthread_create(&disp_thread, NULL, display, (void *)message);
        execute1();
        //ȷ���߳�disp_thread�������̽���ǰ����
        pthread_join(disp_thread, &dis_result);
        break;
    case 2:
        //������̵���ϸ��Ϣ
        input2();
        //��������
        system("CLS");
        //������һ���������ڼ��ӽ��̵��ȵ���ϸ��Ϣ
        pthread_create(&disp_thread, NULL, display, (void *)message);
        execute2();
        //ȷ���߳�disp_thread�������̽���ǰ����
        pthread_join(disp_thread, &dis_result);
        break;
    default:
        printf("Error,please check your command!\n");
        break;
    }
    printf("All processes are finished.\n");
    return 0;
}

//�������ȼ��Խ��̽�������
void sort()
{
    PCB *cur, *pre;
    int ins_flag = 0;

    if ((ready == NULL) || (ptr->priority > ready->priority))
    {
        ptr->link = ready;
        ready = ptr;
    }
    else
    {
        cur = ready;
        pre = cur->link;
        while (pre != NULL)
        {
            if (ptr->priority > pre->priority)
            {
                ptr->link = pre;
                cur->link = ptr;
                pre = NULL;
                ins_flag = 1;
            }
            else
            {
                //�����ȼ���ͣ�����뵽��β
                //���Ҷ�β
                cur = cur->link;
                pre = pre->link;
            }
        }
        if (ins_flag == 0)
        {
            cur->link = ptr;
        }
    }
}

void join()
{
    PCB *p = NULL;

    if (ready == NULL)
    {
        ready = ptr;
    }
    else
    {
        p = ready;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = ptr;
    }

}

void input1()
{
    int i, num;
    printf("Please enter the number of the process: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("the ID of process:No.%d\n", i);
        ptr = getpch(PCB);
        printf("Please enter the name of the process: ");
        scanf("%s", ptr->name);
        printf("Please enter the priority of the process: ");
        scanf("%d", &ptr->priority);
        printf("Please enter the time of the process need: ");
        scanf("%d", &ptr->reqtime);
        printf("\n");
        ptr->runtime = 0;
        ptr->state = READY;
        ptr->link = NULL;
        sort();
    }
}

void input2()
{
    int i, num;
    printf("Please enter the number of the process: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("the ID of process:No.%d\n", i);
        ptr = getpch(PCB);
        printf("Please enter the name of the process: ");
        scanf("%s", ptr->name);
        printf("Please enter the priority of the process: ");
        scanf("%d", &ptr->priority);
        printf("Please enter the time of the process need: ");
        scanf("%d", &ptr->reqtime);
        printf("\n");
        ptr->runtime = 0;
        ptr->state = READY;
        ptr->link = NULL;
        join();
    }
}

void *display(void *arg)
{
    PCB *p = NULL;
    while (ready != NULL)
    {
        p = ready;
        printf("**********************PROCESSES INFO***********************\n");
        printf("name\tstate\tpriority\trequire time\trunning time\n");
        while (p != NULL)
        {
            get_info(p);
            p = p->link;
        }
        Sleep(1000);
        //��������
        system("CLS");
    }
    pthread_exit(0);
    return NULL;
}

int length()
{
    int length = 0;
    PCB *p = ready;
    while(p!=NULL)
    {
        length++;
        p =p->link;
    }

    return length;
}

void get_info(PCB *p)
{
    printf("%s\t", p->name);
    switch (p->state)
    {
    case 0:
        printf("Ready\t");
        break;
    case 1:
        printf("Running\t");
        break;
    case -1:
        printf("Block\t");
        break;
    default:
        printf("UNknow\t");
        break;
    }
    printf("%d\t\t", p->priority);
    printf("%d\t\t", p->reqtime);
    printf("%d\t", p->runtime);
    printf("\n");
}

void destory(PCB *p)
{
    PCB *pre, *cur;
    pre = cur = ready;
    if (p == ready)
    {
        ready = p->link;
    }
    while (!(cur->name == p->name || cur == NULL))
    {
        pre = cur;
        cur = cur->link;
    }
    if (cur != NULL)
    {
        pre->link = cur->link;
    }
    else
    {
        pre->link = NULL;
    }
    p = NULL;
    free(p);
}

void execute1()
{
    int remainder = 0;
    while (ready != NULL)
    {
        ready->state = 1;
        PCB *p = ready;
        while (1)
        {
            //��������ʱ���ʱ��Ƭȡ��
            remainder = p->reqtime % TIME_SLICE;
            if ((p->reqtime - p->runtime) == remainder)
            {
                p->runtime += remainder;
            }
            else
            {
                p->runtime += TIME_SLICE;
            }
            Sleep(1000 * TIME_SLICE);
            if (p->runtime == p->reqtime)
            {
                destory(p);
                break;
            }
        }
    }
}

void execute2()
{
    PCB *p = NULL;
    int remainder = 0;
    while (ready != NULL)
    {
        p = ready;
        while (p != NULL)
        {
            //��������ʱ���ʱ��Ƭȡ��
            remainder = p->reqtime % TIME_SLICE;
            if ((p->reqtime - p->runtime) == remainder)
            {
                p->runtime += remainder;
            }
            else
            {
                p->runtime += TIME_SLICE;
            }
            p->state = 1;
            Sleep(1000 * TIME_SLICE);
            p->state = 0;
            if (p->runtime == p->reqtime)
            {
                destory(p);
            }
            p = p->link;
        }
    }
}