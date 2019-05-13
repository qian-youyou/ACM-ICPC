#include<bits/stdc++.h>
using namespace std;
const int L=1e5+7;
const int inf=0x3f3f3f3f;
const int maxn=1000+7;
int father[maxn],n,m,num[maxn],nPos;    //���ڵ㣨���鼯������������������С�������㼯����ǰ���ʷ�λ
struct node{
    int s,y,w;
}edge[L];   //�߼�����˵㣬�Ҷ˵㣬Ȩֵ
void init(){    //��ʼ�����鼯
    for(int i=0;i<=n;i++)
        father[i]=i;
}
int root(int x){    //���鼯�����츸�ڵ�
    return father[x]==x?x:father[x]=root(father[x]);
}
void unite(int x,int y){    //���鼯���ϲ�������ͨͼ
    x=root(x);
    y=root(y);
    if(x!=y)
        father[y]=x;
}
int alike(int x,int y){ //���鼯���ж��Ƿ�Ϊͬһ��ͨͼ
    return root(x)==root(y);
}
int cmp(node a,node b){ //sort�ṹ������
    return a.w<b.w;
}
int secondTree(int pos) //��С������
{
    init(); //��ʼ��
    int sum=0,cnt=0;
    for(int i=0;i<m;i++)    //����ɾȥ�ߺ��ͼ������С����������
    {
        if(cnt==n-1)
            break;
        if(i==pos)
            continue;
        if(!alike(edge[i].s,edge[i].y)){
            unite(edge[i].s,edge[i].y);
            sum+=edge[i].w;
            cnt++;
        }
    }
    return cnt!=n-1?-1:sum; //�ж�ɾ���ߺ��Ƿ��ܹ�����С������
}
int kruskal(){  //��С������
    init();
    sort(edge,edge+m,cmp);  //�Ա߽���Ȩֵ����
    int sum=0,cnt=0;
    for(int i=0;i<m;i++)    //ÿ��ѡ����С��δ���ʹ���һ����
    {
        if(cnt==n-1)
            break;
        if(!alike(edge[i].s,edge[i].y)){
            unite(edge[i].s,edge[i].y);
            sum+=edge[i].w;
            cnt++;
            num[++nPos]=i;
        }
    }
    return cnt!=n-1?-1:sum; //�жϱ��Ƿ���ڵ���n-1���������-1
}
void read(){    //��������
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&edge[i].s,&edge[i].y,&edge[i].w);
}
void solve(){   //�������
    int Min=inf;
    nPos=0;
    int mst=kruskal();  //��С������ֵ
    if(mst==-1) {   //û����С�����������-1
        printf("-1\n");
        return;
    }
    for(int i=1;i<=nPos;i++){   //����С��������ÿ���߽��б�����ѡ��ɾ�ߺ����Сֵ
        int secmst=secondTree(num[i]);
        if(secmst!=-1)  //��û�д�С���������-1
            Min=min(Min,secmst);
        }
    if(Min!=inf&&Min!=mst)
        printf("%d\n",Min); //������
    else
        printf("-1\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        read(); //��������
        solve();    //�������
    }
    return 0;
}
