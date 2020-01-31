/* woj 213 */
/* c++ */
/* lsy */
#include<stdio.h>
#include<math.h>
int main(){
	int n,i,j;
	double sum;
    while(scanf("%d",&n)!=EOF){
        sum=0.0;
        double a[n][2];
        for(i=0;i<n;i++)
        for(j=0;j<2;j++)
        scanf("%lf",&a[i][j]);
        for(i=0;i<n-1;i++)
        sum+=(a[i][0]*a[i+1][1]-a[i+1][0]*a[i][1])/2.0;
        sum+=(a[n-1][0]*a[0][1]-a[0][0]*a[n-1][1])/2.0;
    	sum=fabs(sum);  
        printf("%d\n",(int)sum);
    }
    return 0;
}