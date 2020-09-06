//https://programming.in.th/task/rev2_problem.php?pid=1061
#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <sstream>
using namespace std;
template <typename T>
void _swap(T& x, T& y)
{

    T temp = x;
    x = y;
    y = temp;
}
template <typename T>
string _tostr(T num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}
vector<int> re;
void _qs()
{

    for (int i = 1; i < re.size(); i++)
        for (int j = re.size() - 1; j >= i; j--)
            if (re[j] > re[j - 1])
                _swap(re[j], re[j - 1]);

    
}
int data[30][30] = {};
int dfs(int x, int y, int n)
{

    if (data[x + 1][y] != 100 and x + 1 <= n and data[x + 1][y] > data[x][y])
        dfs(x + 1, y, n);

    if (data[x - 1][y] != 100 and x - 1 >= 1 and data[x - 1][y] > data[x][y])
        dfs(x - 1, y, n);

    if (data[x][y + 1] != 100 and y + 1 <= n and data[x][y + 1] > data[x][y])
        dfs(x, y + 1, n);

    if (data[x][y - 1] != 100 and y - 1 >= 1 and data[x][y - 1] > data[x][y])
        dfs(x, y - 1, n);

    re.push_back(data[x][y]);
    data[x][y] = 100;
    return 0;
}
int main()
{
    int n;
    int x, y;
    cin >> n;
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> data[i][j];

    dfs(y, x, n);
    re.push_back(0);

    _qs();
    string c = _tostr(re[0]);
    cout << c;
}