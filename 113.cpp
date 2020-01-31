/* woj 113 */
/* c++ */
/* lsy */
#include<iostream>
using namespace std;
int compare(int a,int b,int c,int d)//斜率比较函数，判断在左或是右，或是在同一直线。
{
	return a*b-c*d;
}
struct Point//定义点结构体。
{
	int x;
	int y;
};
int main()
{
	int X,Y,n,x,y,ok,max,i,j,k;
	double r;
	struct Point a[151];
	while(cin>>X>>Y>>r)
	{
		if(r<0)
			break;
		cin>>n;
		for(i=0,k=0;i<n;i++)//输入时只记录在圆内的点。
		{
			cin>>x>>y;
			if( (X-x)*(X-x)+(Y-y)*(Y-y)<=r*r )
			{
				a[k].x=x;
				a[k].y=y;
				k++;
			}
		}
		max=0;
		for(i=0;i<k;i++)
		{
			int cout=1;
			for(j=0;j<k;j++)
				if(j!=i)
				{
					ok=compare(a[i].y-Y,a[j].x-X,a[i].x-X,a[j].y-Y);
					if(ok>=0)//在这儿我将同一直线的点归为到了在右边，都一样的。
						cout++;
				}
			if(k-cout>cout)//另一半的点如果较多，则存入另一半的点数。
				cout=k-cout;
			if(cout>max)
				max=cout;
		}
		cout<<max<<endl;
	}
	return 0;
}
