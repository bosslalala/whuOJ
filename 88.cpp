
#include<stdio.h>
#include<math.h>
#define DS 22
//variable define
int coomm21[DS][DS];

double confumc(int n, int k) {
	if (n < DS) {
		return coomm21[n][k];
	}
	double ans = 1;
	int i;
	for (i = 1; i <= k; ++i)
		ans *= (double)(n - k + i) / (double)i;
	return ans;
}
double power(int k, int a) {
	double ans = 1.0, tmp = k;
	while (a) {
		if (a & 1) {
			ans *= tmp;
		}
		tmp *= tmp;
		a >>= 1;
	}
	return ans;
}
double sfunc(int nn, int mm) {
	double n = nn;
	switch (mm) {
		case 1:
			return (n + 1) * n / 2;
		case 2:
			return sfunc(n, 1) * (2 * n + 1) / 3;
		case 3:
			return sfunc(n, 1) * sfunc(n, 1);
		case 4:
			return sfunc(n, 1) * (6 * n * n * n + 9 * n * n + n - 1) / 15;
		case 5:
			return sfunc(n, 1) * n * (2 * n * n * n + 4 * n * n + n - 1) / 6;
		default: {
			double tmp, ans = 0.0;
			int k, i;
			for (k = 1; k <= mm; ++k) {
				tmp = 0.0;
				for (i = 0; i <= k - 1; ++i) {
					if (i % 2 == 0) {
						tmp += confumc(k, i) * power(k - i, mm);
					} else {
						tmp -= confumc(k, i) * power(k - i, mm);
					}
				}
				ans += tmp * confumc(nn + 1, k + 1);
			}
			return ans;
		}
	}
}
//main code
int main () {
	int i, j;
	for (i = 1; i < DS; ++i) {
		coomm21[i][0] = coomm21[i][i] = 1;
		for (j = 1; j < i; ++j) {
			coomm21[i][j] = coomm21[i - 1][j - 1] + coomm21[i - 1][j];
		}
	}
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF) {
		double ans=sfunc(N,M);
		int b=log10(ans);
		double a=ans/power(10,b);
		printf("%.2fE%d\n",a,b);
	}
	return 0;
}

