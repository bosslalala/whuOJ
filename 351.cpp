/* woj 351 */
/* c++ */
/* lsy */
#include<stdio.h>
int main(){
	int months[9]={0,31,29,31,30,31,30,31,8};
	int t,m,d,sum,i,j;
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d %d",&m,&d);
		for(i=m;i<=8;i++){
			if(i==m)
			sum+=months[i]-d;
			else
			sum+=months[i];
		}
		printf("%d\n",sum);
	}
	return 0;
} 