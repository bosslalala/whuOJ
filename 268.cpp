/* woj 268 */
/* c++ */
/* lsy */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define jz 10000
int a[110][110];
void chengfa(int k,int num){
    int jw = 0;
    for(int i = 100;i >= 0;i--){
        jw += a[k-1][i] * num;
        a[k][i] = jw % jz;
        jw /= jz;
    }
}
void chufa(int k,int num){
    int div = 0;
    for(int i = 0;i <= 100;i++){
        div = div*jz + a[k][i];
        a[k][i] = div / num;
        div %= num;
    }
}
void init(){
    memset(a,0,sizeof(a));
    a[1][100] = 1;
    int num;
    for(int i = 2;i <= 100;i++){
        num = (4*i-2);
        chengfa(i,num);
        num = i+1;
        chufa(i,num);
    }
}
int main()
{
    init();
    int n;
    while(~scanf("%d",&n)){
        if(n==-1) break;
        int pos = -1;
        for(int i = 0;i <= 100;i++){
            if(a[n][i]){
                pos = i;
                break;
            }
        }
        printf("%d",a[n][pos]);
        for(int i = pos+1;i <= 100;i++){
            printf("%04d",a[n][i]);
        }
        puts("");
    }
    return 0;
}