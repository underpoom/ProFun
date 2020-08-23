//https://programming.in.th/task/rev2_problem.php?pid=1007
#include <iostream>
#include <algorithm>
using namespace std;
struct kk
{
    int v = 0;
};
int birth(int b[], int y)
{
    if (y > 0)
    {
        int b0 = b[0], b1 = b[1], b2 = b[2];
        b[1] += b2;
        b[1] += b1;
        b[2] += b1;
        b[1] -= b1;
        b[2] -= b2;
        b[1]++;
        birth(b, y - 1);
    }
    if (y == 0)
    {
        cout << b[1] << " " << b[0] + b[1] + b[2] << endl;
        return 0;
    }


}
int main()
{
    int* b = new int[3];
    
    kk data[26 + 1];
    int n = 0, x = 0;
    while (x != -1)
    {
        cin >> x;
        data[n].v = x;
        n++;
    }
    for (int i = 0; i < n; i++)
    {
        b[0] = 1, b[1] = 1, b[2] = 0;
        birth(b, data[i].v);
    }
}