#include <iostream>
#include <stack>
using namespace std;
int n,x;
int ans=0;     //����������
stack<int> st;
int main()
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		//��x�뵱ǰջ��Ԫ��st.top()�Ƚϣ���ջ������st.top()��x��1����ϲ�һ��(��ʱ����ǰջ��Ԫ�س�ջ)
		//Ȼ��x���ջ���Ƚϣ��Դ����ƣ�ֱ��������ջ������st.top()��x��1
		while(!st.empty() && st.top()-x==1)
		{
			st.pop();
			ans++;
		}
		//��ջ������x��st.top()��1����ϲ�һ��
		//(��ʱ��x"��ջ"��Ҳ���Ǻ��Դ�x��������һ�������x ��ջ�������κα仯)
		if(!st.empty() && x-st.top()==1)
			ans++;
		//�������(xΪ��һ��Ԫ�ػ����������������)����x��ջ
		else
			st.push(x);
	}
	cout<<ans<<endl;
	return 0;
}
