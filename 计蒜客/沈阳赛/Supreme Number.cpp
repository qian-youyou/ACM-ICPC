#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>
using namespace std;
#define N 10000000
int h=0;
bool p[N];
int prime[N];
bool dfs(int x){
    if(p[x]==false)
        return false;
    int c = 1;
    while(c<x){
        c*=10;
        if(p[x%c]==false)
            return false;

        if(c>x)
            break;
        int tmp = x;
        while(tmp){
            if(p[tmp]==false)
                return false;
            if(p[tmp%c]==false)
                return false;
            tmp/=c;
            if(!tmp)
                break;
            if(dfs(tmp)==false)
                return false;
        }
    }
    return true;
}

void db()
{
	memset(p,true,sizeof(p));
	p[0] = false;
	for(int i=2;i<N;i++)
	{
	    if(p[i]==false)
            continue;
		for(int j=2;i*j<N;j++)
		{
			p[i*j]=false;
		}
		if(!dfs(i))
            p[i] = false;
        if(p[i]==true)
		{
			prime[h++]=i;
		}
	}
}
int main()
{
	db();
	int n;  //打印前n个质数
	for(int i=0;i<=h;i++)
		cout<<prime[i]<<",";
	return 0;
}
//2,3,5,7,11,13,17,23,31,37,53,71,73,113,131,137,173,311,317
