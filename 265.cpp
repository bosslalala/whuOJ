/* woj 265 */
/* c++ */
/* lsy */
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int N=10000007;
int a[500005];
bool ha[N];
int main()
{
    memset(a,0,sizeof(a));
    memset(ha,false,sizeof(ha));
    for(int i=1;i<=500000;i++)
    {
        if(a[i-1]-i>0&&!ha[a[i-1]-i])
        {
            a[i]=a[i-1]-i;
        }
        else
            a[i]=a[i-1]+i;
        ha[a[i]]=true;
    }
    int k;
    while(~scanf("%d",&k))
    {
        if(k<0) break;
        printf("%d\n",a[k]);
    }
    return 0;
}