#include <iostream>
#include <stack>
using namespace std;
int n,x;
int ans=0;     //最大操作次数
stack<int> st;
int main()
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		//将x与当前栈顶元素st.top()比较，若栈不空且st.top()比x大1，则合并一次(此时即当前栈顶元素出栈)
		//然后x与次栈顶比较，以此类推，直到不满足栈不空且st.top()比x大1
		while(!st.empty() && st.top()-x==1)
		{
			st.pop();
			ans++;
		}
		//若栈不空且x比st.top()大1，则合并一次
		//(此时即x"出栈"，也就是忽略此x继续看下一个输入的x 但栈不发生任何变化)
		if(!st.empty() && x-st.top()==1)
			ans++;
		//其他情况(x为第一个元素或不满足上述两种情况)：将x入栈
		else
			st.push(x);
	}
	cout<<ans<<endl;
	return 0;
}
