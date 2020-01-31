/* woj 378 */
/* c++ */
/* lsy */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define clr(x,y) memset(x,y,sizeof(x))
#define travel(x) for(Edge *p = last[x]; p; p = p -> pre)
using namespace std;
const int MAX = 110;
inline int read(){
    int ans = 0, f = 1; char c = getchar();
    for(; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for(; isdigit(c); c = getchar()) ans = ans * 10 + c - '0';
    return ans * f;
}
struct Edge{
    Edge *pre; int to;
}edge[10010];
Edge *last[MAX], *pt;
int n, m, inv[MAX], depth[MAX], width[MAX];
bool valid, vis[MAX];
queue <int> q;
inline void addedge(int x,int y){
    pt->pre = last[x]; pt->to = y; last[x] = pt++;
}
void bfs(){
    while (!q.empty()) q.pop();
    rep(i,1,n) if (!inv[i]){
        q.push(i); depth[i] = 0; width[0]++; vis[i] = 1;
    }
    if (q.empty()){
        valid = 0; return;
    }
    while (!q.empty()){
        int now = q.front(); q.pop();
        travel(now){
            if (vis[p->to]){
                valid = 0; return;
            }
            vis[p->to] = 1;
            depth[p->to] = depth[now] + 1;
            width[depth[p->to]]++;
            q.push(p->to);
        }
    }
    rep(i,1,n) if (!vis[i]) valid = 0;
}
void work(){
    m = read();
    pt = edge; clr(last,0); clr(inv,0); clr(width,0); clr(depth,0); clr(vis,0); valid = 1;
    rep(i,1,m){
        int a = read(); int b = read();
        addedge(a,b);
        inv[b]++;
        if (inv[b] > 1) valid = 0;
    }
    if (!valid){
        printf("INVALID\n");
        return;
    }
    bfs();
    if (!valid){
        printf("INVALID\n");
        return;
    }
    int maxdepth = 0; int maxwidth = 0;
    rep(i,1,n){
        maxdepth = max(maxdepth,depth[i]);
        maxwidth = max(maxwidth,width[depth[i]]); 
    }
    printf("%d %d\n",maxdepth,maxwidth);
}
int main(){
    n = read();
    while (n){
        work(); n = read();
    }
    return 0;
}