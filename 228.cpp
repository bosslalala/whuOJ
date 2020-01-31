/* woj 228 */
/* c++ */
/* lsy */
#include<stdio.h>
#include<string.h>
int f,k,sum;
int main()
{
    int i,j;
    while(scanf("%d %d",&f,&k)!=EOF)
    {
        sum=0;
        int a[k][2],b[f+1];
        memset(b,0,sizeof(b));
        for(i=0;i<k;i++)
        scanf("%d %d",&a[i][0],&a[i][1]);
        for(i=0;i<k;i++)
        for(j=a[i][0];j<=f;j+=a[i][1])
            if(b[j]!=1)
                b[j]=1;
        for(i=1;i<=f;i++)
        sum+=b[i];
        printf("%d\n",f-sum);
    }
    return 0;
}