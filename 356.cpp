/* woj 356 */
/* c++ */
/* lsy */
#include<stdio.h>
#include<string.h>
 
int value[1010],height[1010],w,k,MAX,n;
 
int max(int a,int b)
{
	return a>b?a:b;
}
 
void dfs(int x,int hs,int ks,int vs)
{
	if(hs>w || n-x<k-ks) return ;  // 第二个剪枝挺重要的，如果剩下的东西不够做项链就去掉
	if(ks==k)
	{
		MAX=max(MAX,vs);
		return ;
	}
	dfs(x+1,hs+height[x],ks+1,vs+value[x]);
	dfs(x+1,hs,ks,vs);
	return ;
}
 
int main()
{
	int i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=MAX=0;i<n;i++)
			scanf("%d%d",&value[i],&height[i]);
		scanf("%d",&w);
		dfs(0,0,0,0);
		printf("%d\n",MAX);
	}
	return 0;
}