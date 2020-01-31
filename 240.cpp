/* woj 240 */
/* c++ */
/* lsy */
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int INF = 0x3f3f3f3f;
int n, dp[MAXN][3];
vector<int> G[MAXN];
void dfs(int u, int fa)
{
    dp[u][0] = 1;
    dp[u][1] = 0;
    dp[u][2] = INF;
    for (auto v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] += min(dp[v][1], dp[v][0]); //u被占用           
        dp[u][1] += dp[v][2];                //u没被占用,但是u的父亲被占用
        dp[u][2] = min(dp[u][2], dp[u][1] - dp[v][2] + dp[v][0]); //u和u的父亲均没被占用
        if (dp[u][0] > INF) dp[u][0] = INF; //多个INF相加会超int上限
        if (dp[u][1] > INF) dp[u][1] = INF; //多个INF相加会超int上限
    }
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 1; i < n; i++)
        {
            int u, v; scanf("%d%d", &u, &v);
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        dfs(1, -1); 
        printf("%d\n", min(dp[1][0], dp[1][2]));
        int flag; scanf("%d", &flag);
        if (flag == -1) break;
    }
    return 0;
}