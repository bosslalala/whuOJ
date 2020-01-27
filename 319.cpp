/* woj 319 */
/* c++ */
/* lsy */
#include<stdio.h>
#include<string.h>
//char_buffer accelerate input
char char_buffer[128];
int length;
int main(){
    int n,T;
    scanf("%d",&T);
    while(T--){
      	scanf("%d",&n);
      	length=126;
      	if(n==0) char_buffer[length--]='0';
      	char_buffer[127]='\0';
      	while(n!=0){
          	if(n>0)
            switch(n%3){
            	case 0: char_buffer[length--]='0'; n=n/3; break;
            	case 1: char_buffer[length--]='1'; n=(n-1)/3; break;
            	case 2: char_buffer[length--]='-'; n=(n+1)/3; break;    
            }
          	else
            switch(-n%3){
            	case 0: char_buffer[length--]='0'; n=n/3; break;
            	case 1: char_buffer[length--]='-'; n=(n+1)/3; break;
            	case 2: char_buffer[length--]='1'; n=(n-1)/3; break;
          	}
      	}
      	puts(char_buffer+length+1);
    }
    return 0;
}