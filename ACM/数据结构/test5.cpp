#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch;
	int n = 0;
	scanf("%c", &ch);
	while ( ch != '@')
	{
		scanf("%d", &n);
		for (int i = 1; i < n; i++)//��������
		{
			for (int j = 1; j <= i - 1 + n; j++)
			{
				if (j == n - i + 1 || j == i - 1 + n)
					printf("%c", ch);//��ӡ�ַ�
				//����λ�ô�ӡ�ո�
				else
					printf(" ");
			}
			printf("\n");
		}
		//��ӡ���һ��
		for (int i = 0; i < 2 * n - 1; i++)
			printf("%c", ch);
		printf("\n");
		getchar();//���������
		scanf("%c", &ch);
	}
	return 0;
}
