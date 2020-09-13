//https://programming.in.th/task/rev2_problem.php?pid=0033
#include<iostream>
#include<algorithm>
#include<math.h>
template <typename T>void _swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}
struct kk
{
    int n;
    int ns = 0;
};
int _sort(kk data[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (data[j - 1].ns < data[j].ns)_swap(data[j], data[j - 1]);

        }
    }
}
using namespace std;
int main()
{
    kk data[10001];
    int n, id;
    cin >> n;
    while (n--)
    {
        cin >> id;
        data[id].n = id;
        data[id].ns++;
    }
    _sort(data, 10001);
    int v = 0;
    do
    {
        cout << data[v].n << " ";
        v++;
    } while (data[v].ns == data[v - 1].ns);

}