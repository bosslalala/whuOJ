#include<iostream>
using namespace std;

int adult[20],child[20],ans[20];

int main()
{
    child[0]=1;
    adult[0]=0;
    ans[0]=1;
    for(int i=1;i<=18;i++)
    {
        adult[i]=adult[i-1]*3+child[i-1];
        child[i]=adult[i-1]*2+child[i-1]*2;
        ans[i]=adult[i]+child[i];
        //cout<<i<<":"<<adult[i]<<" "<<child[i]<<endl;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
}
