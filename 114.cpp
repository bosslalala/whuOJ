/* woj 114 */
/* c++ */
/* lsy */
//这个代码真丑
#include<stdio.h>
#include<math.h>
int fen(double x,double y){
    double r=x*x+y*y;
    if(r<=3*3)
    return 100;
    else if(r<=6*6)
    return 80;
    else if(r<=9*9)
    return 60;
    else if(r<=12*12)
    return 40;
    else if(r<=15*15)
    return 20;
    else
    return 0;
}
int main(){
    int score1,score2;
    double a1,a2,a3,a4,a5,a6,b1,b2,b3,b4,b5,b6;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",&a1,&a2,&a3,&a4,&a5,&a6,&b1,&b2,&b3,&b4,&b5,&b6)){
        if(a1==-100)
        break;
        score1=fen(a1,a2)+fen(a3,a4)+fen(a5,a6);
        score2=fen(b1,b2)+fen(b3,b4)+fen(b5,b6);
        if(score1==score2)
            printf("SCORE: %d to %d, TIE.\n",score1,score2);
        else if(score1>score2)
            printf("SCORE: %d to %d, PLAYER 1 WINS.\n",score1,score2);
        else
            printf("SCORE: %d to %d, PLAYER 2 WINS.\n",score1,score2);
    }
    return 0;
}
