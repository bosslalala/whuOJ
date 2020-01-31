#include<iostream>
using namespace std;

long long ans[55];
int main()
{
    for(int i=0;i<=50;i++)ans[i]=0;
    ans[0]=1;
    ans[2]=1;
    for(int i=4;i<=50;i+=2)
    {
        for(int j=0;j<=i-2;j+=2)
        {
            ans[i]+=ans[j]*ans[i-2-j];
        }
    }
    int n;
    while(cin>>n)
    {
        cout<<ans[n]<<endl;
    }
}