#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <deque>
const int inf = 1 << 30, maxn = 100000 + 11, M = 200000 + 11  ;
using namespace std ;//1061109567
int n, m, head[maxn], dis[maxn], cnt, sum, tot ;
bool mark[maxn] ;
struct id
{
    int nxt,to, val ;
} edge[M] ;
deque < int > Q ;


inline void Init ( )
{
    freopen( "NSOOJ#10719.in", "r", stdin  ) ;
    freopen( "NSOOJ#10719.out", "w", stdout ) ;
}

int read( )
{
    char ch = getchar( ) ;
    int k = 1, ret = 0 ;
    while( ch < '0' || ch > '9' )
    {
        if( ch == '-' )
            k = -1 ;
        ch = getchar( ) ;
    }
    while( ch >= '0' && ch <= '9' )
        ret = ret * 10 + ch - '0', ch = getchar( ) ;
    return k * ret ;
}

void add( int u, int v, int va )
{
    edge[++cnt].nxt = head[u], edge[cnt].to = v ;
    edge[cnt].val = va, head[u] = cnt ;
}

void input(  )
{
    n = read(), m = read( ) ;
    int u,v, c ;
    memset( head, -1, sizeof(head)) ;
    for( int x = 1 ; x <= m ; ++x )
    {
        u = read( ), v = read( ), c = read( ) ;
        add( u,v, c )  ;
    }
}

void spfa( )
{
    memset( dis, 127/2, sizeof(dis) ) ;
    dis[1] = 0, mark[1] = true ;
    Q.push_back( 1 ) ;
    while( !Q.empty( ) )
    {
        int u = Q.front( ) ;
        Q.pop_front( ) ;
        mark[u] = false ;

        for( int i = head[u] ; ~i ; i = edge[i].nxt )
        {
            int v = edge[i].to ;
            if( dis[v] > dis[u] + edge[i].val )
            {
                dis[v] = dis[u] + edge[i].val ;
                if( !mark[v] )
                {
                    mark[v] = true ;
                    if( Q.empty( ) || dis[v] > dis[Q.front( )]  )
                        Q.push_back( v ) ;
                    else
                        Q.push_front( v ) ;

                }

            }
        }
    }
    if( dis[n] == 1061109567 )
        printf( "%d\n", -1 ) ;
    else
        printf( "%d\n", dis[n] ) ;
}


int main( )
{
//    Init( ) ;
    input( ) ;
    spfa( ) ;
//    fclose( stdin ) ;
//       fclose( stdout ) ;
    return 0 ;
}
