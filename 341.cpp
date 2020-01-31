/* woj 341 */
/* c++ */
/* lsy */
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define  inf 0x0f0f0f0f
 
using namespace std;
 
const double PI=acos(-1.0);
const double EPS=1e-8;
typedef pair<int,int>pii;
 
struct max_clique
{
    static const int N=100;
    bool G[N][N];
    int n,Max[N],Alt[N][N],ans;
 
    bool DFS(int cur,int tot)
    {
        if (cur==0)
        {
            if (tot>ans)
            {
                ans=tot;
                return true;
            }
            return false;
        }
        for (int i=0;i<cur;i++)
        {
            if (cur-i+tot<=ans) return false;
            int u=Alt[tot][i];
            if (Max[u]+tot<=ans) return false;
            int nxt=0;
            for (int j=i+1;j<cur;j++)
            if (G[u][Alt[tot][j]]) Alt[tot+1][nxt++]=Alt[tot][j];
            if (DFS(nxt,tot+1)) return true;
        }
        return false;
    }
 
    int maxclique()
    {
        ans=0;
        memset(Max,0,sizeof(Max));
        for (int i=n-1;i>=0;i--)
        {
            int cur=0;
            for (int j=i+1;j<n;j++) if (G[i][j]) Alt[1][cur++]=j;
            DFS(cur,1);
            Max[i]=ans;
        }
        return ans;
    }
};
 
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    char str[100][100];
    scanf("%d",&T);
    while (T--)
    {
        max_clique friends;
        scanf("%d",&friends.n);
        for (int i=0;i<friends.n;i++) scanf("%s",str[i]);
        for (int i=0;i<friends.n;i++)
        for (int j=0;j<friends.n;j++)
        {
            if (str[i][j]=='0') friends.G[i][j]=false;
            else friends.G[i][j]=true;
        }
        printf("%d\n",friends.maxclique());
    }
    //fclose(stdin);
    return 0;
}