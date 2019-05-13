#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
	vector<int>grade[120];
	double res[120];
	int N, K, M,temp;
	double temp1;
	while (cin >> N>> K>> M)
	{
		memset(res, 0, 105 * sizeof(double));
		for (int j = 0; j < N; ++j)//6
		{
			for (int i = 0; i < K; ++i)//5
			{

				cin >> temp;
				grade[j].push_back(temp);
			}
			sort(grade[j].begin(), grade[j].end());
			grade[j].erase(grade[j].begin());
			grade[j].erase(grade[j].end() - 1);
			temp = 0;
			for (int i = 0; i < grade[j].size(); ++i)
				temp += grade[j][i];
			res[j] =(double) temp / (grade[j].size());
		}
		for (int p = 0; p<N; p++)
			for (int l = p + 1; l<N; l++)
				if (res[p] > res[l])
				{
					temp1 = res[p];
					res[p] = res[l];
					res[l] = temp1;
				}
		for (int i = M; i<=K; ++i)
		{
			cout << fixed<<setprecision(3)<< res[i];
			if(i!=K)
				cout << ' ';
		}
		cout << endl;
		for (int i = 0; i < N; ++i)
			grade[i].clear();
	}
	return 0;
}
