#include <stdio.h>
int main()
{
    int t;
	int n=0;
	int i,j;
	int a[107];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<t-1;)
	{
		if(a[i]-a[i+1]==1)
		{
			for(j=i;j<t-1;j++)
			a[j]=a[j+1];
			t--;
			n++;
		}
		if(a[i]-a[i+1]==-1)
		{
			for(j=i;j<t-1;j++)
			a[j+1]=a[j+2];
			t--;
			n++;
		}
		if((a[i]-a[i+1]!=1)&&(a[i]-a[i+1]!=-1))
		i++;
    }
	printf("%d",n);
	for(i=0;i<t;i++)
	printf("%d ",a[i]);
}
