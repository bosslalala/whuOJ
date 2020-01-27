#include <stdio.h>  
int main(){
    //variable 
	int n,Ssmax;
    int i,j;
	int s[10001],p[10001],f[100010];

    // main code 
    
	while(scanf("%d",&n)==1){
		for(i=1;i<=n;i++){
			scanf("%d %d",&s[i],&p[i]);
		}
		scanf("%d",&Ssmax);
		for(j=0;j<=Ssmax;j++){
			f[j]=0;
		}
		for(i=1;i<=n;i++){
			for(j=Ssmax;j>=1;j--){
				if(j-s[i]>=0)
				f[j]=f[j]>(f[j-s[i]]+p[i])?f[j]:(f[j-s[i]]+p[i]); 
			}
		}
		printf("%d\n",f[Ssmax]);
	}
	return 0;
}

