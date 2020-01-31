/* woj 209 */
/* c++ */
/* lsy */
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int n,num1[50000],num2[50000];
int main() {
	int i,j,k,l;
	priority_queue<int,deque<int>,less<int> > big;
	while(scanf("%d",&n)!=EOF) {
		for(i=0; i<n; i++)
			scanf("%d",&num1[i]);
		sort(num1,num1+n);
		for(j=0; j<n; j++) {
			scanf("%d",&num2[j]);
			big.push(num1[0]+num2[j]);
		}
		sort(num2,num2+n);
		for(k=1; k<n; k++)
			for(l=0; l<n; l++) {
				if(num1[k]+num2[l]>big.top())
					break;
				big.pop();
				big.push(num1[k]+num2[l]);
			}
		for(k=0; k<n; k++) {
			num1[n-k-1]=big.top();
			big.pop();
		}
		printf("%d",num1[0]);
		for(i=1; i<n; i++)
			printf(" %d",num1[i]);
	}
	return 0;
}