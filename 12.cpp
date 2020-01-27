#include <stdio.h>
#include <string.h>

// main code

int main()
{
    char in[2001];
    long flag[2001], i, min, Ssum[2001], Ppre[2001], j, k, n, m, s, p;
    long long dout;

    while (scanf("%ld %ld\n", &n, &m) != EOF)
    {
        for (i = 1; i <= m; i++)
            flag[i] = 0;
        for (s = 1, dout = 0; s <= n; s++)
        {
            gets(in);
            for (i = 0; i < m; i++)//记录第i列到s行连续出现的白方块数,滚动数组1,处理单列上的白方块总数
            {
                if (in[i] == 'w')
                    flag[i + 1]++;
                else
                    flag[i + 1] = 0;
            }
            for (i = 1, flag[0] = Ppre[0] = 0; i <= m; i++)
            {
                //如果比前列的白方块数多,可以直接加入
                if (flag[i] >= flag[i - 1])
                {
                    //滚动数组2,记录前i列的白方块总数
                    Ssum[i] = Ssum[i - 1] + flag[i];
                    Ppre[i] = 0;
                }
                else
                {
                    Ppre[i] = Ppre[i - 1] + 1;
                    p = i - Ppre[i];
                    //找出比这列flag[]小的列
                    while (p > 0 && flag[p - 1] >= flag[i])
                        p = p - Ppre[p - 1] - 1;
                    //这列flag[]值最小
                    if (p <= 0)
                    {
                        Ssum[i] = flag[i] * i;
                        Ppre[i] = 0;
                    }
                    //p列flag[]值最小
                    else
                    {
                        Ssum[i] = flag[i] * (i - p + 1) + Ssum[p - 1];
                        Ppre[i] = i - p - 1;
                    }
                }
                dout += Ssum[i];
            }
        }
        printf("%lld\n", dout);
    }
    return 0;
}