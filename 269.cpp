#include <stdio.h>
int n,m;
int main(){
	int i,j,sp;
	while(scanf("%d%d",&n,&m)==2) {
		if(n==-1&&m==-1) break;
		sp=1;
		while(sp*(sp-1)/2<m) sp++;
		int k=n-sp;
		for(i=1; i<=k; i++) printf("%d ",i);
		int first=m-(sp-1)*(sp-2)/2;
		printf("%d ",first+1+k);
		for(i=sp; i>1; i--) {
			if(i==first+1) continue;
			printf("%d ",i+k);
		}
		printf("%d\n",i+k);
	}
	return 0;
}