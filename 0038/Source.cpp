//https://programming.in.th/task/rev2_problem.php?pid=0038
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char data[1001][31] = {};

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%s", data[i]);

    for (int i = 29; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            for (int k = 0; k < j; k++)
            {
                if (data[k][i] > data[k + 1][i])swap(data[k], data[k + 1]);
            }
        }
    }


    string a, b;

    for (int i = 0; i < n - 1; i++)
    {
        a = data[i];
        b = data[i + 1];
        if (a == b)
            data[i][0] = '-';

    }

    for (int i = 0; i < n; i++)
        if (data[i][0] != '-')
            printf("%s\n", data[i]);




}