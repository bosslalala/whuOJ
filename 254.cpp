/* woj 254 */
/* c++ */
/* lsy */
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
#define N 100000
#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u>>2;
int d[12],dd[12];
int an[12];
void judge(int xx,int x[],int f)
{
    if(!xx) return ;
    int i,j,e;
    int p[12],g=0;
    int y = xx;
    while(xx)
    {
        p[++g] = xx%10;
        xx/=10;
    }
    int o = 1;
    x[0]+=1;
    for(i = g ; i >= 1 ; i--)
    {
        for(i==g?j = 1:j=0 ; j < p[i] ; j++)
        {
            x[j]+=pow(10.0,g-o);
        }
        for(j = i-1 ; j>=1 ; j--)
        {
            int ko;
            if(i==g)
            {
                if(j==i-1)
                ko = pow(10.0,g-o-1)*(p[i]-1);
                else
                ko = pow(10.0,g-o-1)*(p[i]-1)+(pow(10.0,(i-j-1))-1)*pow(10.0,j-1);
            }
            else ko = pow(10.0,g-o-1)*p[i];
            //cout<<ko<<" "<<i<<" "<<j<<" "<<o<<endl;
            x[0]+=ko;
            for(e = 1 ; e <= 9 ; e++)
            {
                x[e]+=pow(10.0,g-o-1)*p[i];
            }
        }
        int k = pow(10.0,g-o);
        x[p[i]] += y%k+1;
        o++;
    }

    if(f)
    {
        for(i = 1 ;i <= g ;i++)
        x[p[i]]--;
    }
}
int main()
{
    int i,a,b;
    while(cin>>a>>b)
    {
        if(!a&&!b) break;
        if(a>b) swap(a,b);
        memset(d,0,sizeof(d));
        memset(dd,0,sizeof(dd));
        judge(a,d,1);
        judge(b,dd,0);
        for(i = 0 ;i < 9 ;i++)
        cout<<dd[i]-d[i]<<" ";
        cout<<dd[9]-d[9]<<endl;
    }
    return 0;
}