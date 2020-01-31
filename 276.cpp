#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1005
using namespace std;
int n,h,a[N];
bool dfs(int x,int dep)
{
	if(dep>h)  return false;
	if(x==n)  return true;
	if(x<<(h-dep)<n)  return false;
	a[dep]=x;
	for(int i=0;i<=dep;++i)
	{
		if(dfs(a[i]+x,dep+1))  return true;
		if(dfs(abs(a[i]-x),dep+1))  return true;
	}
	return false;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		h=0;
		while(!dfs(1,0))  h++;
		printf("%d\n",h);
	}
	return 0;
}
