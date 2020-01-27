/* woj 303 */
/* c++ */
/* lsy */
#include <iostream>
#include <map>
#include <cstdio>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
map<string, int> mp;
const int AX = 1e3 + 666;
int n, m;
int id;
char tmp[100];
char tmp2[100];
struct Node
{
    int type;
    int quality;
    int price;
} s[AX];
bool func(int x)
{
    int count = 0;
    int minprice[AX];
    int budget = 0;
    memset(minprice, INF, sizeof(minprice));
    for (int i = 1; i <= n; i++)
    {
        if (s[i].quality < x)
            continue;
        if (minprice[s[i].type] == INF)
        {
            count++;
            minprice[s[i].type] = s[i].price;
            budget += s[i].price;
        }
        else if (minprice[s[i].type] > s[i].price)
        {
            budget = budget - minprice[s[i].type] + s[i].price;
            minprice[s[i].type] = s[i].price;
        }
    }
    return (count == id - 1 && budget <= m);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int maxquality = 0;
        id = 1;
        mp.clear();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s%s", tmp, tmp2);
            if (!mp[tmp])
            {
                mp[tmp] = id++;
                s[i].type = mp[tmp];
            }
            else
            {
                s[i].type = mp[tmp];
            }
            scanf("%d%d", &s[i].price, &s[i].quality);
            maxquality = max(maxquality, s[i].quality);
        }
        int l = 0, r = maxquality;
        //for(int i=1;i<=n;i++) cout<<s[i].type<<endl;
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;
            if (func(mid))
                l = mid;
            else
                r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}