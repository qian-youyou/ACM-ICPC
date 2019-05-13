#include <stdio.h>
#include <string.h>
struct
{
    int x,y;
}p[150],p1[150];			//p1暂时用来存枚举每个面积的小球坐标，p为最终结果
char map[10][16];
int wide,minx,miny,v[10][15],walk[4][2]={{1,0},{-1,0},{0,1},{0,-1}};		//minx，miny是每个面积最小行和列
void updata()
{
    int i,i1,i2,pos=0;
    for(i=0;wide>i;i++)
    {
        i2=9;
        for(i1=9;i1>=0;i1--)
        {
            if(map[i1][i]!='0')
            {
                map[i2][i-pos]=map[i1][i];
                i2--;
            }
        }
        if(i2==9)		//当前列无小球，移动到前pos列
        {
            pos++;
        }
        else
        {
            while(i2>=0)			//填充
            {
                map[i2][i-pos]='0';
                i2--;
            }
        }
    }
    wide=wide-pos;			//宽度减少
}
int bfs(char c,int x,int y)
{
    int i,f=0,top=0;
    p1[0].x=x;
    p1[0].y=y;
    minx=10-x;
    miny=y+1;
    v[x][y]=1;
    top++;
    while(f<top)
    {
        for(i=0;4>i;i++)
        {
            x=p1[f].x+walk[i][0];
            y=p1[f].y+walk[i][1];
            if(x<10&&x>=0&&y<wide&&y>=0&&v[x][y]==0&&map[x][y]==c)
            {
                p1[top].x=x;
                p1[top].y=y;
                v[x][y]=1;
                if(miny>y+1||(miny==y+1&&minx>10-x))				//记录该面积最小行列
                {
                    minx=10-x;
                    miny=y+1;
                }
                top++;
            }
        }
        f++;
    }
    return top;
}
int main()
{
    int i,i1,i2,i3,i4,t,sum,num,max,temp,x,y;
    char c;
    scanf("%d",&t);
    for(i=1;t>=i;i++)
    {
        sum=0;					//总分
        num=150;				//小球剩余个数
        wide=15;				//初始化矩阵宽度
        max=0;					//最大面积
        for(i1=0;10>i1;i1++)
        {
            scanf("%s",map[i1]);
        }
        printf("Game %d:\n\n",i);
        for(i1=1;max!=1&&num!=0;i1++)
        {
            max=0;
            memset(v,0,sizeof(v));
            for(i2=9;i2>=0;i2--)				//枚举每个小球，求最大面积，从行最小开始
            {
                for(i3=0;wide>i3;i3++)
                {
                    if(map[i2][i3]=='0'||v[i2][i3]==1)			//当前格子无小球或者已经过搜索
                    {
                        continue;
                    }
                    temp=bfs(map[i2][i3],i2,i3);
                    if(max<temp||(max==temp&&y>miny))			//最大面积且列最小，进行更新
                    {
                        x=minx;
                        y=miny;
                        max=temp;
                        c=map[i2][i3];
                        for(i4=0;temp>i4;i4++)
                        {
                            p[i4]=p1[i4];
                        }
                    }
                }
            }
            if(max!=1)
            {
                num=num-max;				//数据以及地图的更新
                sum=sum+(max-2)*(max-2);
                for(i2=0;max>i2;i2++)
                {
                    map[p[i2].x][p[i2].y]='0';
                }
                updata();
                printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points. \n",i1,x,y,max,c,(max-2)*(max-2));
            }
        }
        if(num==0)				//奖励分
        {
            sum=sum+1000;
        }
        printf("Final score: %d, with %d balls remaining. \n\n",sum,num);
    }
    return 0;
}
