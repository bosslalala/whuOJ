/* woj 226 */
/* c++ */
/* lsy */
#include<cstdio>
#include<cstring>
int n,m,map[20][20];
int opt[20][20];//保存最优解 
int flip[20][20];//保存中间结果 
int dir[5][2]={{1,0},{-1,0},{0,0},{0,-1},{0,1}};
 
int judge(int x,int y)//查询（x,y）的颜色 
{
	int i,c=map[x][y];
	for(i=0;i<5;++i)
	{
		int x2=x+dir[i][0],y2=y+dir[i][1];
		if(0<=x2&&x2<n&&0<=y2&&y2<m)
			c+=flip[x2][y2];
	}
	return c%2;
}
 
int calc()
{
	int i,j,res;
	for(i=1;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(judge(i-1,j)!=0)//上方格子是黑色，必须必须反转（i,j）号格子 
				flip[i][j]=1; 
		}
	}
	for(i=0;i<m;++i)//判断最后一行是否全白 
	{
		if(judge(n-1,i)!=0)//当前方案不行 
			return -1;
	}
	res=0;
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			res+=flip[i][j];//统计当前方案的反转次数 
		}
	}
	return res;
}
 
int main()
{
	int i,j,ans,num;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
				scanf("%d",&map[i][j]);
		}
		ans=-1;
		//按照字典序尝试第一行所有的可能性，方案为2^m种 
		for(i=0;i< 1<<m;++i)
		{
			memset(flip,0,sizeof(flip));
			for(j=0;j<m;++j)
				flip[0][m-j-1]=i>>j&1;
			num=calc();
			if(num>=0&&(ans<0||ans>num))
			{
				ans=num;
				memcpy(opt,flip,sizeof(flip));//把flip数组复制给opt数组 
			}
		}
		if(ans==-1)
			printf("IMPOSSIBLE\n");
		else
		{
			for(i=0;i<n;++i)
			{
				for(j=0;j<m;++j)
				{
					if(j==m-1)
						printf("%d\n",opt[i][j]);
					else
						printf("%d ",opt[i][j]);
				}
			}
		}
	}
	return 0;
}