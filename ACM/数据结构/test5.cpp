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
		for (int i = 1; i < n; i++)//控制行数
		{
			for (int j = 1; j <= i - 1 + n; j++)
			{
				if (j == n - i + 1 || j == i - 1 + n)
					printf("%c", ch);//打印字符
				//其余位置打印空格
				else
					printf(" ");
			}
			printf("\n");
		}
		//打印最后一行
		for (int i = 0; i < 2 * n - 1; i++)
			printf("%c", ch);
		printf("\n");
		getchar();//清除缓冲区
		scanf("%c", &ch);
	}
	return 0;
}
