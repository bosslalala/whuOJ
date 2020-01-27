#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  
#include<iostream>  
using namespace std;  
//存储数所在的位置  
int high1[65537];
//金刚想要数所在的位置  
int high2[65537];
//第一行数  
int a[5001];  
//第二行数  
int b[5001];  
//标记这个数是否移动到所想位置  
bool flag[5001];
int main()  
{  
    //freopen("in.txt", "r", stdin);  
    int n, i, k, tp, cost, q,min;  
    while (scanf("%d", &n) != EOF && n != 0)  
    {  
        min = 65538;  
        memset(flag, 0, sizeof(flag));  
        cost = 0;  
        for (i = 1; i <= n; i++)  
        {  
            scanf("%d", &a[i]);  
            if (a[i] < min) min = a[i];  
            cost += a[i];//每个数都至少要交换一次  
            high1[a[i]] = i;  
        }  
        for (i = 1; i <= n; i++)  
        {  
            scanf("%d", &b[i]);  
            high2[b[i]] = i;  
        }  
        for (i = 1; i <= n; i++)  
            if (!flag[i])  
            {  
                tp = 65538;//记录循环中最小的数  
                q = i;  
                k = 0;//循环个数  
                do//找到循环个数和循环中最小的数  
                {  
                    flag[q] = true;  
                    if (b[q] < tp)  
                        tp = b[q];  
                    q = high1[b[q]];  
                    k++;  
                }while (q != i);  
                cost += (k - 2) * tp < tp + (k + 1) * min ? (k - 2) * tp : tp + (k + 1) * min;//两种方式中选择小的  
            }  
        printf("%d\n", cost);  
    }  
    return 0;  
}  
