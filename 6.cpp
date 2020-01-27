#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

#define MAXX 0x7fffffff

//variables define

//g是图的连接关系
vector<int> g[200005];
//dis[t]表示源点到t点的距离
int n,m,dis[200005];

//spfa 算法实现
void spfa(int s)
{
    bool vis[200005];
    queue<int> q;
    memset(vis,false,sizeof(vis));
    dis[s]=0;
    q.push(s);
    vis[s]=true;

    //循环
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<g[p].size();i++)
        {
            int r=g[p][i];
            if(dis[r]>dis[p]+1)
            {
                dis[r]=dis[p]+1;
                if(!vis[r]){vis[r]=true;q.push(r);}
            }
        }
        vis[p]=false;
    }
}

//主函数
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k;
    cin>>k;
    for(int t=0;t<k;t++)
    {
        int a,b;
        cin>>a>>b;
        if(a==b){cout<<0<<endl;continue;}
        for(int i=0;i<n;i++)dis[i]=MAXX;

        spfa(a);

        if(dis[b]==MAXX)cout<<"-1"<<endl;
        else cout<<dis[b]-1<<endl;
    }
}
