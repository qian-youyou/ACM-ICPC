#include <stdio.h>
struct information{
	int pid;
	int allocation[3];
	int max[3];
	int need[3];
	int safe;
	struct information *next;
}process[5];
void Bankers();
void sequence();
int available[5];
int request[3];
int temp[4][3];
int temp2[3];
int re_pid;
void main(int argc,char *argv[])
{
	FILE *fp;
	int num[40];
	int cnt = 3;
	int i=0,j=0,k,l;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Fail to read file.\n");
		exit(1);
	}
	else
	{
		printf("<Read file>\n");
		for (i = 0; i < 35; i++)
		{
			fscanf(fp, "%d", &num[i]);
		}
		for (i = 0; i < 3; i++)
		{
			available[i] = num[i];
			printf("%2d", available[i]);
		}
		for (i = 0; i < 4; i++)
		{
			process[i].pid = num[cnt];
			cnt = cnt + 7;
		}
		cnt = 4;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 3; j++)
			{
				process[i].allocation[j] = num[cnt];
				cnt++;
			}
			cnt = cnt + 4;
		}
		cnt = 7;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 3; j++)
			{
				process[i].max[j] = num[cnt];
				cnt++;
			}
			cnt = cnt + 4;
		}
		re_pid = num[31];
		for (i = 0; i < 3; i++)
		{
			request[i] = num[i + 32];
		}
		printf("\n");
		for (i = 0; i < 4; i++) //print the input file
		{
			printf("%d   ", process[i].pid);
			for (j = 0; j < 3; j++)
			printf("%2d", process[i].allocation[j]);
			printf("  ");
			for (j = 0; j < 3; j++)
			printf("%2d", process[i].max[j]);
			printf("\n");
		}
		printf("%d   ", re_pid);
		for (i = 0; i < 3; i++)
		printf("%2d", request[i]);
		printf("\n\n<Banker's Algorithm>\n\n");
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 3; j++)
			{
				process[i].need[j] = process[i].max[j] - process[i].allocation[j];
				temp[i][j] = process[i].need[j] - request[j];
				temp2[j] = available[j] - request[j];
			}
		}
		for (i = 0; i < 4; i++)
		{
			process[i].safe = 0;
		}
		//before request
		sequence();
		for (i = 0; i < 4; i++)
		{
			process[i].safe = 0;
		}
		for (i = 0; i < 3; i++)
		{
			available[i] = num[i];
			printf("%2d", available[i]);
		}
		Bankers();
	}
	fclose(fp);
}
void Bankers()
{
	struct information *p, *prev, *head = NULL;
	int i, j,cnt=0,num=0;
	printf("\n\n<P%d's Request>\n\n",re_pid);
	printf("Current State : ");
	for (i = 1; i < 5; i++)
	{
		if (temp[i % 4][0] >= 0 && temp[i % 4][1] >= 0 && temp[i % 4][2] >= 0)
		{
			if (temp2[0] >= 0 && temp2[1] >= 0 && temp2[2] >= 0 && process[i % 4].safe != 1)
			{
				process[i % 4].safe = 1;
				cnt++;
				if (cnt == 1){
					head = &process[i % 4];
					prev = head;
				}
				else{
					p = &process[i % 4];
					prev->next = p;
					prev = prev->next;
					p->next = NULL;
				}
				for (j = 0; j < 3; j++)
				{
					available[i % 4] = available[j] - request[j];
					process[i % 4].allocation[j] = process[i % 4].allocation[j] + request[j];
					process[i % 4].need[j] = process[i % 4].need[j] - request[j];
				}
			}
		}
	}
	if (cnt != 4)
	printf(" X\nThis system is in unsafe state.\n");
	else{
		while (head)
		{
			printf(" P%d ", head->pid);
			head = head->next;
			num++;
			if (num != 4)
			printf("->");
		}
		printf("\nThis system is in a safe state.\n");
	}
}
void sequence()
{
	struct information *p, *prev, *head = NULL;
	int i, j, k, count = 0, num = 0;
	for (k = 0; k < 4; k++)
	{
		for (i = 0; i < 4; i++){
			if ((process[i].need[0] <= available[0]) && (process[i].need[1] <= available[1]) && (process[i].need[2] <= available[2] && process[k].safe != 1))
			{
				process[k].safe = 1;
				count++;
				if (count == 1){
					head = &process[k];
					prev = head;
				}
				else{
					p = &process[k];
					prev->next = p;
					prev = prev->next;
					p->next = NULL;
				}
				for (j = 0; j < 3; j++)
				available[j] = available[j] + process[i].allocation[j];
			}
		}
	}
	if (count != 4)
	{
		printf("\nThis system is in unsafe state.\n");
	}
	else{
		printf("Current State : ");
		while (head)
		{
			printf(" P%d ", head->pid);
			head = head->next;
			num++;
			if (num != 4)
			printf("->");
		}
		printf("\nThis system is in a safe state.\n");
	}
}
