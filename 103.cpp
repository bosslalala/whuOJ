/* woj 103 */
/* c++ */
/* lsy */
#include<iostream>
#include<string>
using namespace std;

int fcker(string s)
{
    int ret=s[0]-'0',i=1;
    while(s[i++]!='%')ret=ret*10+s[i-1]-'0';
    return ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double ans;
        string s;
        cin>>s;
        int p=fcker(s);
        ans=100.0*(p*p)/(p*p+(100-p)*(100-p));
        printf("%.2f\%\n",ans);
    }
}