/* woj 110 */
/* c++ */
/* lsy */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 400000+10;
 
struct Rect{
    Rect(int ll=-1 ,int rr=-1,int tt=-1,int bb=-1)
        : l(ll) , r(rr) , t(tt) , b(bb) { }
    int l,t,r,b;
}frame[30];
 
char block[31][31];
bool vis[30];
char ans[MAX][30];
int top,h,w,Index=0;
 
int cmp(const void * s1 , const void * s2)
{
    return strcmp((char*)s1,(char*)s2);
}
bool find_rect(char ch)
{
    int l=100,t=100,b=-1,r=-1;
    for(int i=0;i<h;++i)
    {
        for(int j = 0 ; j < w ; ++j)
        if(block[i][j]==ch)
        {
            if (l > j) l = j;
            if (t > i) t = i;
            if (b < i) b = i;
            if (r < j) r = j;
        }//确定矩形的位置，左上和右下
    }
    if (b==-1) return false;//没有对应字母的矩形
    frame[ch-'A']=Rect(l,r,t,b);
    return true;
}
 
bool can_put(char ch)
{
    if (frame[ch-'A'].l==-1) return false;
    int r = frame[ch-'A'].t;
    int c = frame[ch-'A'].l;
    while (c < frame[ch-'A'].r)
    {
        if (block[r][c]==ch || vis[block[r][c]-'A']) ++c;
        else return false;
    }
    while (r < frame[ch-'A'].b)
    {
        if (block[r][c]==ch || vis[block[r][c]-'A']) ++r;
        else return false;
    }
    while (c > frame[ch-'A'].l)
    {
        if (block[r][c]==ch || vis[block[r][c]-'A']) --c;
        else return false;
    }
    while (r > frame[ch-'A'].t)
    {
        if (block[r][c]==ch || vis[block[r][c]-'A']) --r;
        else return false;
    }
    return true;
}
 
void dfs(int rest)
{
    if (rest==0)
    {
        ans[top++][Index] = '\0';
        strcpy(ans[top],ans[top-1]);
        return;
    }
    for(char ch='A';ch<='Z';++ch)
    if(!vis[ch-'A']&&can_put(ch))
    {
        ans[top][Index++] = ch;
        vis[ch-'A'] = true;
        dfs(rest-1);
        --Index;
        vis[ch-'A'] = false;
    }
}
 
void solve()
{
    int cnt = 0;
    for (char ch='A';ch<='Z';ch++)   if(find_rect(ch)) ++cnt;
    dfs(cnt);
    char buffer[30];
    for (int i=0;i<top;++i)
    {
        strcpy(buffer,ans[i]);
        for (int j=0;j<cnt;++j) ans[i][j]=buffer[cnt-1-j];//倒序
    }
    qsort(ans,top,sizeof(ans[0]),cmp);
    for (int i=0;i<top;++i) printf("%s\n",ans[i]);
}
int main(){
    while(scanf("%d %d",&h,&w)==2&&(h!=0&&w!=0)){
        for(int i=0;i<h;++i) scanf("%s",block[i]);
        for(int i=0;i<26;++i) frame[i]=Rect();
        top = 0;
        memset(vis,false,sizeof(vis));
        solve();
    }
}
