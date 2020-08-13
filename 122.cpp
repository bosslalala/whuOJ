/* woj 122 */
/* c++ */
/* lsy */
#include<cstdio>  
#include<cstring> 

int gcd(int a,int b)  
{  
    return b==0?a:gcd(b,a%b);  
}   
int d[36];  
int num[36];  
int main()  
{  
    int n;  
    while(scanf("%d",&n)&&n)  
    {  
    for(int i=1;i<=n;i++)  
    scanf("%d",&d[i]);  
    int total=0;  
    memset(num,0,sizeof(num));  
    for(int i=n;i>=1;i--)  
    {  
        for(int j=1;j<=d[i];j++)  
        {  
            total++;  
            for(int k=i+1;k<=n;k++)  
            if(d[k]>=j)  
            num[total]++;  
            else  
            break;  
            num[total]+=d[i]-j+1;  
        }     
    }  
    long long int t1=1,t2=1;  
    for(int i=1;i<=total;i++)  
    {  
        t1*=i;   
        t2*=num[i];  
        int t=gcd(t1,t2);  
        t1/=t;  
        t2/=t;  
    }  
    printf("%lld\n",t1/t2);  
   }  
   return 0;  
}  