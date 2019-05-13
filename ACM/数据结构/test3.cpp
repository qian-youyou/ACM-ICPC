#pragma warning(disable: 4996)

#include <stdio.h>

int main()
{
	int N = 0;
	int M = 0;
	int K = 0;
	int array[1001][1001] = { 0 };
	int count[1001] = { 0 };
	int i = 0;
	int j = 0;
	int sum = 0;

	printf("input:");
	while (scanf("%d%d%d", &N, &M, &K) != EOF)
	{
		if (K != 0)
		{

			while (--K)
			{
				int x1, x2, y1, y2;
				int max_x, max_y, min_x, min_y;
				int _count = 0;

				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				max_x = x1 > x2 ? x1 : x2;
				max_y = y1 > y2 ? y1 : y2;
				min_x = x1 < x2 ? x1 : x2;
				min_y = y1 < y2 ? y1 : y2;

				for (i = min_x; i < max_x; ++i)
				{
					for (j = min_y; j < max_y; ++j)
					{
						if (array[i][j] == 0)
						{
							array[i][j] = 1;
							_count++;
						}

					}
				}
				count[K] = _count;
			}
		}
		else
		{
			break;
		}
	}
	for (i = 0; i < 1001; ++i)
	{
		sum += count[i];
	}
	printf("%d\n", sum);

	return 0;
}
