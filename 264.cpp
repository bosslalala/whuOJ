/* woj 264 */
/* c++ */
/* lsy */
#include<cstdio>
#include<stack>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<cmath>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=110;
const int nmax = 60200;
const double esp = 1e-9;
const double PI=3.1415926;
char a[7][13]={"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
int judge(int y){
if((y%4==0&&y%100!=0)||y%400==0)
      return 366;
return 365;
}
int num_month(int ans,int mon){
if(mon==2){
      return ans==366?29:28;
}
if(mon==2||mon==4||mon==6||mon==9||mon==11)
      return 30;
return 31;
}
int main()
{
    int n,y,m,w;
    while(scanf("%d",&n)!=EOF){
      if(n==-1)
            break;
      int sum=0,ans;
      w=n%7;
      for(int i=2000;i<10000;i++){
            ans=judge(i);
            if(sum+ans<=n){
                  sum+=ans;
                  continue;
            }
            else{
                 y=i;
                 n-=sum-1;  //此时的n为该年的第n天
                 m=1;
                 int num=num_month(ans,m);
                 while(n>num){
                  n-=num;
                  m++;
                  num=num_month(ans,m);
                 }
                 break;
            }
      }
      printf("%d-%02d-%02d %s\n",y,m,n,a[w]);
    }
    return 0;
}