/* woj 329 */
/* c++ */
/* lsy */
#include<stdio.h>
#include<string.h>
char str[100][100],rem[100];

int t1[]={-1,-1,-1,0,0,1,1,1};
int t2[]={-1,0,1,-1,1,-1,0,1};
int len,m,n;

void Rever(int row,int col,int ans)
{
    if(str[row][col]>='A' && str[row][col]<='Z') str[row][col]+=32;
    if(rem[ans]>='A' && rem[ans]<='Z') rem[ans]+=32;
}

int Action(int row,int col)
{
    int ans=0,i;
    int x=row,y=col;
    Rever(row,col,ans);
    if(str[row][col]!=rem[ans]) return 0;
    for (i=0;i<8;i++)
    {
        ans=0;
        while(1)
        {
            Rever(row,col,ans);
            if(row<0 || col<0 || row>=m || col>=n || str[row][col]!=rem[ans]) break;
            {
                if(ans==len-1) return 1;
                ans++;
                row+=t1[i];col+=t2[i];
            }
        }
        row=x;col=y;
    }
    return 0;
}

int main()
{
    int i,j;
    int T,x,k;
    int flag;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for (i=0;i<m;i++)
        {
            scanf("%s",str[i]);
        }
        scanf("%d",&x);
        for (k=0;k<x;k++)
        {
            scanf("%s",rem);
            len=strlen(rem);
            for (i=0;i<m;i++)
            {
                for (j=0;j<n;j++)
                {
                    flag=0;
                    flag=Action(i,j);
                    if(flag) break;
                }
                if(flag) break;
            }
            printf("%d %d\n",i+1,j+1);
        }
        if(T!=0) printf("\n");
    }
    return 0;
}