/* woj 222 */
/* c++ */
/* lsy */
#include<iostream>  
#include<algorithm>  
#define inf 1e8  
using namespace std;  
int dp[2020][2020];  
int main()  
{  
        int n,m,vis[30];  
        scanf("%d%d",&n,&m);
            char a[2020];  
            scanf("%s",a); //Input string
            int x,y;  
            char z;  
            for(int i=0;i<n;i++)  
            {  
                cin>>z>>x>>y;  
                vis[z-'a']=min(x,y); //Take the smallest price
            }  
            /*if(m==1)                //These two can be removed, but with the words, time will be much less
            { 
                printf("0\n"); 
                continue; 
            } 
            if(m==2) 
            { 
                dp[0][1]=min(vis[a[0]-'a'],vis[a[1]-'a']); 
                printf("%d\n",dp[0][1]); 
                continue; 
            }*/  
            for(int j=1;j<m;j++)  
            {  
                for(int i=j-1;i>=0;i--)  
                    {  
                        dp[i][j]=inf; //Assign infinity
                        if(a[i]==a[j])  
                            dp[i][j]=dp[i+1][j-1];  //Lean against the center
                        else {  
                            dp[i][j]=min(dp[i+1][j]+vis[a[i]-'a'],dp[i][j-1]+vis[a[j]-'a']);//Modify the cheapest way
                        }  
                    }  
            }  
            printf("%d\n",dp[0][m-1]);  //The optimal solution from 0 to M-1 (as from 0)

        return 0;  
}  