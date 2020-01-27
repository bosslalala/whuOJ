/* woj 329 */
/* c++ */
/* lsy */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
char array1[1001]={0}, array2[1001]={0};
 
int main()
{
	while(gets(array1) && gets(array2))
	{
		int len1=strlen(array1);
		int len2=strlen(array2);
		
		sort(array1, array1+len1);
		sort(array2, array2+len2);
		
		int i, j;
		for(i=0, j=0; i<len1 && j<len2; )
		{
			if(array1[i]==' ' || array1[i]>='A' && array1[i]<='Z') i++;
			if(array2[j]==' ' || array2[j]>='A' && array2[j]<='Z') j++; //移除空格或者是大写字母
			if(array1[i]==array2[j])
			{
				printf("%c",array1[i]);
				i++;
				j++;
			}
			if(array1[i]<array2[j]) i++;
			if(array1[i]>array2[j]) j++;
		}
		printf("\n");
		
		memset(array1, 0, sizeof(array1));
		memset(array2, 0, sizeof(array2));
	}
}