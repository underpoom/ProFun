//https://programming.in.th/task/rev2_problem.php?pid=0039
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{

    int n, b, x;
    cin >> n >> b;
    int data[n + 2];

    for (int i = 0; i < n; i++)
        data[i] = i + 1;
    bool ban[n + 2] = {};
    for (int i = 0; i < b; i++)
    {
        cin >> x;
        ban[x] = 1;
    }

    do
    {
        if (ban[data[0]] == 1)continue;
        for (int i = 0; i < n; i++)
            cout << data[i] << " ";

        cout << endl;

    } while (next_permutation(data, data + n));
}