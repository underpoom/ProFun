//https://programming.in.th/task/rev2_problem.php?pid=0019
#include <iostream>
#include <algorithm>
using namespace std;
int ingredient[12][2], result = 2e10, v = 0;

int min(int x, int y)
{
    return (x <= y) * x + (x > y) * y;
}
int bc(int data[], int k, int n)
{
    if (k == n)
    {
        if (v != 0)
        {
            int sour = 1, bitter = 0;
            for (int i = 1; i <= n; i++)
            {
                if (data[i])
                    sour *= ingredient[i][0];
                if (data[i])
                    bitter += ingredient[i][1];
            }

            result = min(abs(sour - bitter), result);
        }
        v = 1;

    }
    else
    {

        data[k + 1] = 0;
        bc(data, k + 1, n);
        data[k + 1] = 1;
        bc(data, k + 1, n);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ingredient[i][0] >> ingredient[i][1];
    }
    int data[n + 1];
    bc(data, 0, n);
    cout << result;
}