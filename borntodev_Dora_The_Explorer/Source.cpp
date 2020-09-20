//https://www.borntodev.com/grader/?quizNo=314
#include <iostream>
using namespace std;
template <typename T>
void dfs(string data[], T x, T y, T mx, T my)
{
    data[x][y] = '.';
    int i[] = { -1, 0, 1, 0 }, j[] = { 0, 1, 0, -1 };
    for (int v = 0; v < 4; v++)
        if (i[v] + x >= 0 and j[v] + y >= 0 and data[i[v] + x][j[v] + y] == '#' and i[v] + x < mx and j[v] + y < my)
            dfs(data, i[v] + x, j[v] + y, mx, my);
    data[x][y] = '.';
}
int main()
{
    int x, y, island = 0;
    cin >> x >> y;

    string c[x + 1] = {};
    for (int i = 0; i < x; i++)
        cin >> c[i];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (c[i][j] == '#')
            {
                island++;
                dfs(c, i, j, x, y);
            }

    cout << island;
}