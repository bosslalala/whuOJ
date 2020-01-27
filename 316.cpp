/* woj 316 */
/* c++ */
/* lsy */
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    int n,r,tmp,k,flag,i;
    int a[102];
    while (scanf("%d %d",&n,&r)!=EOF){        
        if(n==0&&r==0) break;
        if(n==0)// 0 is special
        {
            printf("0\n");
            continue;
        }
        r*=-1;
        //label the number: a negative or positive number
        flag=1;
        if(n<0){
            flag=0;
            n*=-1;
        }
        //translate a decimal number into R-representation number
        k=0;
        memset(a,0,sizeof(a));
        while(n!=0){
            tmp=n%r;
            a[k++]=tmp;
            n/=r;
        }
        //translate a R-representation number into a -R-representation number
        i=0;
        while(i<k||a[i]){
            if(a[i]>=r){
                a[i]%=r;
                a[i+1]++;
            }
            if(i%2==flag&&a[i]){
                a[i]=r-a[i];
                a[i+1]++;
            }
            i++;
        }
        //output the answer
        for(i=i-1;i>=0;i--){
            if(a[i]>9) printf("%c",'A'+a[i]-10);
            else printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}