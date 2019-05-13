#include<stdio.h>
#include<string.h>
#include <iostream>
#include<stack>
using namespace std;
int main(void)
{
  char a[1001];
  while(gets(a)!=NULL)
  {
    int cnt,n,j;
    n=strlen(a);
    for(int i=0;i<n;i++)
    {
      if(a[i]=='B') j=i;
    }
      cnt=0;
      stack<char>s;
      for(int i=0;i<n;i++)
      {
        if(i<j&&a[i]=='(') s.push(a[i]);
        if(!s.empty()&&a[i]==')')
        {
           s.pop();
           if(i>j)
           cnt++;
         }
        if(s.empty()) break;
      }
      printf("%d\n",cnt);
  }
  return 0;
}
