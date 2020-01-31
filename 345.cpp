/* woj 341 */
/* c++ */
/* lsy */
#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 100
using namespace std;
class BigInt{
public:
    int v[512],L;
    BigInt(){
        memset(v,0,sizeof(v)); L=1;
        adjust();
    }
    BigInt(int x){
        memset(v,0,sizeof(v));
        v[0]=x; L=0;
        adjust();
    }
    //大数的加法
    void add(const BigInt &T){
        int i;
        if (L<T.L) L=T.L;
        for (i=0;i<L;i++)
            v[i]+=T.v[i];
        adjust();
    }
    //大数的乘法
    void mul(const BigInt &T){
        int i,j;
        BigInt Y(0);
        for (i=0;i<T.L;i++) for (j=0;j<L;j++){
            Y.v[i+j]+=T.v[i]*v[j];
        }
        *this=Y;
        L=L+T.L;
        adjust();
    }
    void adjust(){
        int i;
        for (i=0;i<L;i++){
            v[i+1]+=v[i]/MOD;
            v[i]%=MOD;
        }
        //向前进位
        while (v[L]){
            v[L+1]+=v[L]/MOD;
            v[L]%=MOD;
            L++;
        }
    }
    void display(){
        int i;
        printf("%d",v[L-1]);
        for (i=L-2;i>=0;i--) printf("%02d",v[i]);//保持2个0
        printf("\n");
    }
};
BigInt B[320],T;
int N;
int main(){
    //freopen("in.txt","r",stdin);
    int i,j,N;
    B[0]=*(new BigInt(1));//带参数的初始化
    B[1]=*(new BigInt(1));
    for (i=2;i<301;i++){
        for (j=0;j<i;j++){
            T=B[j];
            T.mul(B[i-j-1]);//B[j]*B[i-j-1]
            B[i].add(T);//B[i]+T
        }
    }
    scanf("%d",&N);
    while (N--){
           scanf("%d",&i);
        B[i].display();
    }
    //fclose(stdin);
    return 0;
}