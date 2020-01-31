#include<iostream>
using namespace std;

int mx[15][15];

int main()
{
    mx[1][0]=-1;
    for(int i=1;i<=12;i++)
    {
        mx[1][i]=mx[1][i-1]+i;
        for(int j=2;j<=12;j++)
        {
            mx[j][i]=mx[j-1][i]+i-2+j;
        }
    }
    //for(int i=1;i<=12;i++){for(int j=1;j<=12;j++)cout<<mx[i][j]<<" ";cout<<endl;}

    int m,n;
    while(cin>>m>>n)
    {
        if(m==0&&n==0)break;
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n-i+1;j++)cout<<mx[i][j]+m<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
}