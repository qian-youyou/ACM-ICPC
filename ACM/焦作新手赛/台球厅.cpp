#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //�����
const int maxn = 60007;
const int maxm = 1000007;
int vis[maxn],d[maxn],pre[maxn],a[maxn],m,n;    //�Ƿ���ʣ����·��ǰ�ýڵ㣬�������߼����㼯
char mp[107][107];  //̨���ͼ
struct Edge{
    int u, v, c, cost, next;
}edge[maxm];    //�������߼�

int s[maxn], cnt;   //ÿ��������

void init(){    //��ʼ��
	cnt = 0;
	memset(s, -1, sizeof(s));
}

void add(int u, int v, int c, int cost){    //������֮����е���߽���
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].cost = cost;
	edge[cnt].c = c;
	edge[cnt].next = s[u];
	s[u] = cnt++;   //���������
	edge[cnt].u = v;
	edge[cnt].v = u;
	edge[cnt].cost = -cost;
	edge[cnt].c = 0;
	edge[cnt].next = s[v];
	s[v] = cnt++;   //����˫���
}

bool spfa(int ss, int ee,int &flow,int &cost){  //�Ծ���Ϊ����Ѱ�����·�������·Ϊ��ǰ����·
	queue<int> q;
	memset(d, INF, sizeof d);
	memset(vis, 0, sizeof vis); //��ʼ��
	d[ss] = 0, vis[ss] = 1, pre[ss] = 0, a[ss] = INF;
	q.push(ss);
	while (!q.empty()){ //spfa�Է���Ϊ����Ѱ�����·
		int u = q.front();q.pop();
		vis[u] = 0;
		for (int i = s[u]; ~i; i = edge[i].next){   //�͵�ǰ���������б��ɳڹ���
			int v = edge[i].v;
			if (edge[i].c>0&& d[v]>d[u] + edge[i].cost){    //�ɳڹ���
				d[v] = d[u] + edge[i].cost;
				pre[v] = i;
				a[v] = min(a[u], edge[i].c);    //ȡ��Сֵ
				if (!vis[v]){
					vis[v] = 1;
					q.push(v);     //ѹ����ɳڶ���
				}
			}
		}
	}
	if (d[ee] == INF) return 0; //�ж��Ƿ������·����˵����������
	flow += a[ee];
	cost += d[ee]*a[ee];
	int u = ee;
	while (u != ss){    //��ǰ���·�µ�������
		edge[pre[u]].c -= a[ee];
		edge[pre[u] ^ 1].c += a[ee];
		u = edge[pre[u]].u;
	}
	return 1;
}

int MCMF(int ss, int ee){   //��С���������
	int cost = 0, flow=0;   //��ʼ��
	while (spfa(ss, ee, flow, cost));   //Ѱ������·����ֱ��û������·��Ϊֹ
	return cost;    //�������������
}

struct point{
    int x,y;    //�����꣬������
};

void solve(){
    point H[107],P[107];    //�������붴��
    int h=0,p=0;
    for(int i=0;i<n;i++){   //�����ͼ
        scanf("%s",&mp[i]);
        for(int j=0;j<m;j++){
            if(mp[i][j]=='#'){  //��Ϊ����������붴��
                H[h].x=i;
                H[h].y=j;
                h++;
            }
            else if(mp[i][j]=='@'){ //��Ϊ�������������
                P[p].x=i;
                P[p].y=j;
                p++;
            }
        }
    }
    init(); //��ʼ��
    for(int i=0;i<h;i++)
        for(int j=0;j<p;j++){
        int c=fabs(H[i].x-P[j].x)+fabs(H[i].y-P[j].y);
             add(i+1,h+j+1,1,c);
        }   //�������붴֮���·��
    for(int i=0;i<h;i++)    //��������Դ��
        add(0,i+1,1,0);
    for(int i=0;i<p;i++)    //�����������
        add(h+1+i,h+p+1,1,0);
    printf("%d\n",MCMF(0,h+p+1));   //��С���������
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        if(!(m||n))
            break;
        solve();    //�������
    }
	return 0;
}
