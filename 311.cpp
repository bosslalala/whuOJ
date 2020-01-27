/* woj 311 */
/* c++ */
/* lsy */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define min(a,b)(a<b?a:b)
// function 
void change(int a[])
{
    int i;
    for(i=1;i<=60;i++)
    a[i]=1;
}
struct cars{
    int h;
    int l;
}car[2600];

int positon[60];

int main(){
    int i,j,T,H,L,num,temp,time,dis;
    scanf("%d",&T);
    while(T--){
    num=0,time=0;
    scanf("%d %d",&H,&L);
    for(i=1;i<=H;i++){
    for(j=1;j<=L;j++){
        scanf("%d",&temp);
    if(temp!=-1){
        num++;
        car[temp].h=i;
        car[temp].l=j;
    }
    }
    }
    change(positon);
    for(i=1;i<=num;i++){
    time=time+(car[i].h-1)*20;
    time=time+min(abs(car[i].l-positon[car[i].h]),L-abs(car[i].l-positon[car[i].h]))*5;
    positon[car[i].h]=car[i].l;
    }
    printf("%d\n",time);
}
    system("pause");
    return 0;
}