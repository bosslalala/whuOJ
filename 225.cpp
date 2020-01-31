/* woj 225 */
/* c++ */
/* lsy */
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
bool vis[100005];
struct point
{
    int place,count;
};
int main()
{
    int n,k;
    point x,temp;
    while(~scanf("%d %d",&n,&k))
    {
        if(n==k) {printf("%d\n",0);continue;}
        memset(vis,0,sizeof(vis));
        queue<point> q;
        point head={n,0};
        q.push(head);
        vis[n]=1;
        while(!q.empty())
        {
            x=q.front();
            q.pop();
            temp=x;
            temp.place-=1;
            if(temp.place>=0&&vis[temp.place]==0)
            {
                ++temp.count;
                if(temp.place==k) {printf("%d\n",temp.count);break;}
                q.push(temp);vis[temp.place]=1;
            }
            temp=x;
            temp.place+=1;
            if(temp.place<=100000&&vis[temp.place]==0)
            {
                ++temp.count;
                if(temp.place==k) {printf("%d\n",temp.count);break;}
                q.push(temp);vis[temp.place]=1;
            }
            temp=x;
            temp.place*=2;
            if(temp.place<=100000&&vis[temp.place]==0)
            {
                ++temp.count;
                if(temp.place==k) {printf("%d\n",temp.count);break;}
                q.push(temp);vis[temp.place]=1;
            }
        }
    }
    return 0;
}