/* woj 340 */
/* c++ */
/* lsy */
#include<stdio.h>
#include<string.h>
int main(){
    int i,t,j,l,n;
    scanf("%d",&t);
    char name_array[2][200];
    for(i=0;i<t;i++){
    	scanf("%s %s",&name_array[0],&name_array[1]);
    	for(j=0;j<2;j++){
    		l=strlen(name_array[j]);
    		n=0;
    		while(n<l){
    			if((n==0)&&(name_array[j][0]>='a')&&(name_array[j][0]<='z'))
    			name_array[j][0]-=32;
    			else if((n>0)&&(name_array[j][n]>='A')&&(name_array[j][n]<='Z'))
				name_array[j][n]+=32;
				n++;
			}
		}
		printf("%s %s\n",name_array[1],name_array[0]);
	}
	return 0;
}