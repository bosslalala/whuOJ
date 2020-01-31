/* woj 262 */
/* c++ */
/* lsy */
#include <stdio.h>

#include <iostream>

#include <string.h>

using namespace std;



int ans = 0x7fffffff;



void Shift(int row, int n, int matrix[10][10])

{

    int temp = matrix[row][n - 1];

    for (int i = n - 1; i > 0; i--)

    {

        matrix[row][i] = matrix[row][i - 1];

    }

    matrix[row][0] = temp;

}



void DFS(int index, int n, int matrix[10][10])

{

    if (index == n)

    {

        return;

    }

    int maxsum = -100000000;

    for (int i = 0; i < n; i++)

    {

        int sum = 0;

        for (int j = 0; j < n; j++)

        {

            sum += matrix[j][i];

        }

        if (sum > maxsum)

        {

            maxsum = sum;

        }

    }

    if (maxsum < ans)

    {

        ans = maxsum;

    }

    for (int i = 0; i < n; i++)

    {

        Shift(index, n, matrix);

        DFS(index + 1, n, matrix);

    }

}



int main()

{

    int n;

    int matrix[10][10]; 

    while(scanf("%d", &n) != EOF && n != -1)

    {

        ans = 0x7fffffff;

        for (int i = 0; i < n; i++)

        {

            for (int j = 0; j < n; j++)

            {

                scanf("%d", &matrix[i][j]);

            }

        }

        DFS(0, n, matrix);

        printf("%d\n", ans);

    }

    return 0;

}