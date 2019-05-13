#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const double minl = 0.0001;
double equationor(double y)
{
	return (8 * y*y*y*y + 7 * y*y*y + 2 * y*y + 3 * y + 6);
}
int main()
{
	int T;
	int Y;
	cin >> T;
	while (T--)
	{
		cin >> Y;
		if (Y<equationor(0) || Y>equationor(100))
		{
			cout << "No solution!" << endl;
			break;
		}
		double xl = 0, xr = 100, x;
		while (xr-xl>minl)
		{
			x = (xl + xr) / 2;
			if (equationor(x) > Y)
			{
				xr = x;
			}
			else if (equationor(x) < Y)
			{
				xl = x;
			}
		}
		printf("%.4lf\n", x);
	}
	system("pause");
	return 0;
}
