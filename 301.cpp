/* woj 301 */
/* c */
#include <stdio.h>
int a[100005];
int main(void)
{
    int T;
    scanf("%d",&T);	//读入测试案例的个数
    while(T--)
    {
        int num,S;
        scanf("%d%d",&num,&S);
        int min=num,sum=0;
        int i,j;
        for(i=0;i<num;i++)
            scanf("%d",&a[i]);	//初始化数据
        for(i=0,j=0;;)			//尺取代码
        {
            while(i<num&&sum<S)
                sum+=a[i++];
            if(sum<S)break;
            if(min>(i-j))
                min=i-j;
            sum-=a[j++];
        }
        if(min>=num&&sum<S)	//判断答案是否合法
            min=0;
        printf("%d\n",min);
    }
}