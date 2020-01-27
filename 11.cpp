#include<stdio.h>
#include<iostream>
#define reep(i, n) for (long long  i = 1; i <= (n); ++i)

using namespace std;

long long  ccomb(long long  n, long long  k){
	long long  a=1, b=1,c=1;
	if (k > n - k)   k = n - k;
	reep(i, k)
		a *= n+1-i;
	reep(i, k)
		b *= i;
	return a/b;
}
// function code
long long  F(long long  n){
	if (n == 0)
		return 1;
	if (n >= 0 && n <= 3)
		return 1;
	long long  x = n/ 3;
	long long  ans = 0;
	
	reep(i, x)
		ans += F(3 * i - 1)*F(n - 3 * i)*ccomb(n - 1, 3 * i - 1);
	if (n % 3 == 2)
		ans += F(n - 1);
	return ans;
}

// main code
int main(){
	long long  nt;
	while (cin>>nt)
	{
		if (!nt)
			cout << 0 << endl;
		else
		{
			long long anst = F(nt);
			cout << anst << endl;
		}
	}
}