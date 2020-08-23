//https://programming.in.th/task/rev2_problem.php?pid=1017
#include <iostream>
#include <algorithm>
using namespace std;
struct kk
{
    int v = 0;
};
int main()
{
    int n;
    cin >> n;
    int data[10 + 2][10 + 2];

    kk* bit = new kk[102];
    int v = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> data[i][j];
            if (bit[data[i][j]].v == 0)
                bit[data[i][j]].v = 1;
            else
                v = 1;
        }
    int result = 0;
    for (int i = 0; i < n; i++)
        result += data[0][i];
    int testresult;
    for (int i = 0; i < n; i++)
    {
        testresult = 0;
        for (int j = 0; j < n; j++)
            testresult += data[i][j];
        if (result != testresult)
            goto skip;
        testresult = 0;
        for (int j = 0; j < n; j++)
            testresult += data[j][i];
        if (result != testresult)
            goto skip;
    }
    testresult = 0;
    for (int i = 0; i < n; i++)
        testresult += data[i][i];
    if (result != testresult)
        goto skip;

    testresult = 0;
    for (int i = 0; i < n; i++)
        testresult += data[n - 1 - i][i];
    if (result != testresult)
        goto skip;

    if (v == 1)
        goto skip;
    cout << "Yes";
    return 0;
skip:
    cout << "No";
}