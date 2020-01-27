/* woj 302 */
/* c++ */
/* lsy */
#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<iostream>
using namespace std;
int z,h,x,y,m,answer;
int func(int a,int b){
	int base=a%m,answer=1;
	while (b!=0){
		if (b&1==1) answer*=base,answer%=m;
		base*=base,base%=m;
		b>>=1;
	}
	return answer;
}
int main()
{
	scanf("%d",&z);
	while (z--){
		answer=0;
		scanf("%d",&m);
		scanf("%d",&h);
		for (int i=1;i<=h;i++){
			scanf("%d%d",&x,&y);
			answer+=func(x,y)%m,answer=answer%m;
		}
		printf("%d\n",answer);
	}
	return 0;
}
