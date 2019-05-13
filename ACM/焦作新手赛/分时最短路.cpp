#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 0x3f3f3f3f;
const int maxn = 1e5+7;
int t,n,m,cnt;
int dis[maxn];  //��ǰ�õ㵽ԭ����̾���
bool vis[maxn]; //�Ƿ���ʹ�
int head[maxn]; //�㼯
struct EDGE{
    int next,to,w,l,r;  //��һ���ߣ���һ���㣬Ȩֵ����ֵ����ֵ
}edge[2*maxn];  //�߼�
struct NODE{
    int u,dis;
    NODE(){}
	NODE(int u,ll w):u(u),dis(w){}
	bool operator <(const NODE &a)const{
		return dis>a.dis;
	}
}node[2*maxn];  //�㼯����̾���
void add(int u, int v, int w, int l,int r){ //�����߼�
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].l = l;
    edge[cnt].r = r;
    head[u] = cnt;
    cnt++;
}
void init(){    //��ʼ��
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(dis,maxx,sizeof(dis));
    memset(vis,false,sizeof(vis));
}
void read(){    //��������
    int u,v,w,l,r;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m; i++){
        scanf("%d%d%d%d%d",&u,&v,&w,&l,&r);
        add(u,v,w,l,r);
        add(v,u,w,l,r);
    }
}
void init_data(int kk){ //��ʼ������
    vis[kk] = false;
    dis[kk] = maxx;
}
int solve(int s){
    priority_queue<NODE>q;  //������̾���
    q.push(NODE(s,0));  //����ԭ��
    while(!q.empty()){  //����Ϊ�����޷�����
        int kk = q.top().u; //���浱ǰ��̾����±�
        int minD = q.top().dis; //���浱ǰ��̾���
        q.pop();
        if(kk==n)   //���±�ΪĿ��ֵ��return
            return minD;
        vis[kk] = true; //�õ��Ƿ����
        for(int l = head[kk]; l!=-1; l=edge[l].next){   //�ɳڱ�
            if(!vis[edge[l].to]&&minD<=edge[l].r&&minD>=edge[l].l&&minD + edge[l].w < dis[edge[l].to]){
                dis[edge[l].to] = minD + edge[l].w;
                q.push(NODE(edge[l].to,dis[edge[l].to]));   //���ɳں�ı�ѹ�����
            }
        }
        init_data(kk);  //��ʼ������
    }
    return 0;
}
int main(){
    scanf("%d",&t);
    while(t--){
        init(); //��ʼ��
        read(); //����
        printf("%d\n",solve(1));    //�������
    }
    return 0;
}
