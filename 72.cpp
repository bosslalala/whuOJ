#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 10001

// variable define

int N,p,k;
int deep[MAX];
int T[MAX];
typedef struct nt {
	int start,end,length;
	bool operator < (const nt a)const {
		if(start == a.start)
			return a.end > end;
		else
			return start < a.start;
	}
} TS;

TS node[MAX];

int main() {
	while(scanf("%d", &N) != EOF) {
		for(int i = 0; i < N; i ++) {
			scanf("%d %d",&node[i].start, &node[i].end);
			node[i].length = node[i].end - node[i].start + 1;
		}
		stable_sort(node,node+N);
		memset(deep,0,sizeof(deep));
		deep[0] = node[0].length;
		T[0] = node[0].length;
		for(int i = 1; i < N; i ++) {
			int s = i - 1;
			T[i] = node[i].length;
			int dT = 0;
			for(; s >=0; s --) {
				if(node[i].start > node[s].end)
					dT = max(dT ,T[s]);
			}
			T[i] += dT;
			deep[i] = max(deep[i-1],T[i]);
		}
		printf("%d\n",deep[N - 1]) ;
	}
	return 0;
}
