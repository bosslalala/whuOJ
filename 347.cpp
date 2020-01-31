/* woj 347 */
/* c++ */
/* lsy */
#include <iostream>
#include<stdio.h>
using namespace std;
const int INF=0x3f3f3f3f;
int  deep[150][150],value[150];
int main()
{
    int n,k,a,b,lim,i,j,l,t,ans;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&a,&b,&k);
        for(i=0;i<n;i++)
            scanf("%d",&value[i]);
        ans=deep[0][0]=value[0];
        for(i=1;i<n;i++)
        {
            lim=min(i,k);
            for(j=1;j<=lim;j++)
            {
                deep[i][j]=-INF;
                for(l=a;i-l>=0&&l<=b;l++)//注意范围
                    deep[i][j]=max(deep[i][j],deep[i-l][j-1]+value[i]);
                ans=max(ans,deep[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
