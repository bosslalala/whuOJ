#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
 //variable define
int dirtion[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
 
struct node
{
	int x,y;
	int step;
	bool operator < (const struct node &tmp)const
	{
		return step > tmp.step;
	}
};
 
int map[410][410];
int ex,ey;
int vis[410][410];
priority_queue <struct node> que;
 
int BFSaltho()
{
	memset(vis,0,sizeof(vis));
	while(!que.empty()) que.pop();
 
	vis[1][1] = 1;
	que.push((struct node){1,1,0});
 
	while(!que.empty())
	{
		struct node u = que.top();
		que.pop();
 
		if(u.x == ex && u.y == ey)
		{
			return u.step;
		}
 
		for(int d = 0; d < 4; d++)
		{
			int x = u.x+dirtion[d][0];
			int y = u.y+dirtion[d][1];
			if(map[x][y] != 1 && !vis[x][y])
			{
				vis[x][y] = 1;
				if(map[x][y] == 0)
					que.push((struct node) {x,y,u.step});
				else que.push((struct node) {x,y,u.step+1});
			}
		}
	}
	return -1;
}
int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		if(n == -1 && m == -1) break;
		int x,y,d,t;
		memset(map,0,sizeof(map));
		
		//建图
		while(n--)
		{
			scanf("%d %d %d %d",&x,&y,&d,&t);
			if(d == 1)
			{
				for(int i = y*2; i <= (y+t)*2; i++)
					map[x*2][i] = 1;
			}
			else
			{
				for(int i = x*2; i <= (x+t)*2; i++)
					map[i][y*2] = 1;
			}
		}
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&d);
			if(d == 1)
				map[2*x][2*y+1] = 2;
			else map[2*x+1][2*y] = 2;
		}
		double e_x,e_y;
		scanf("%lf %lf",&e_x,&e_y);
		if(e_x < 0 || e_x > 199 || e_y < 0 || e_y > 199)//终点原本就不再sea内，就没必要经过门
		{
			printf("0\n");
			continue;
		}
 
		ex = (int)e_x*2+1;
		ey = (int)e_y*2+1;
 
		for(int i = 0; i <= 400; i++) 			//周围加一道墙
			map[i][0] = map[i][400] = map[0][i] = map[400][i] = 1;
		int ans = BFSaltho();
		printf("%d\n",ans);
	}
	return 0;
}
