#include <stdio.h>
#define MAX 10000

//main code
int main() {
	
	int Ttime[8][MAX],tmp[MAX],Ddata[100];
	int n,min;
    int i, j, Rrop;
    Rrop=0;
 
	while(scanf("%d",&n) == 1) {
		min = 0;
		for(i=0; i<8; i++)
			for(j=0; j<n; j++)
				scanf("%d",&Ttime[i][j]);
		for(j=0; j<n; j++)
			tmp[j] = Ttime[0][j];
		for(j=0; j<n; j++) {
			for(i=0; i<8; i++) {
				tmp[j] = (tmp[j] < Ttime[i][j])? tmp[j]:Ttime[i][j];
			}
			min = min + tmp[j] ;
		}
		Ddata[Rrop]=min;
		Rrop++;
	}
	for(i=0; i<Rrop; i++)
		printf("%d\n",Ddata[i]);
	return 0;
}