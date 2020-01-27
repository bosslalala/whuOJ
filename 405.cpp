#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

const long mod = 1000000007;
long x[1005];
//func
long eul(long n)
{
    long rres = 1, i;
    for(i = 2; i * i <= n; i ++)
    {
        if(n % i == 0)
        {
            n /= i;
            rres *= (i - 1);
            while(n % i == 0)
                n /= i, rres *= i;
        }
    }
    if(n > 1)
        rres *= n - 1;
    return rres;
}
//main code
int main()
{
    int n, i;
    long rres;
    while(scanf("%d", &n) != EOF)
    {
        rres = 1;
        for(i = 0; i < n; i ++)
            scanf("%ld", &x[i]);
        sort(x, x + n);
        for(i = 0; i < n; i ++)
            rres = ((long long)rres * (long long)eul(x[i])) % mod;
        printf("%ld\n", rres);
    }
    return 0;
}