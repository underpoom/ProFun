//https://programming.in.th/task/rev2_problem.php?pid=1099
#include <iostream>
#include<vector>
#include<math.h>

using namespace std;
template <typename T> void _swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}
vector<long long> _sort(vector<long long>& data, long long size)
{

    for (long long i = 1; i < size; i++)
    {
        for (long long j = size - 1; j >= i; j--)
            if (data[j] < data[j - 1])_swap(data[j], data[j - 1]);

    }
    return data;
}
int main()
{
    int x, y;
    cin >> x >> y;
    vector<long long>data;
    for (long long i = 1; i <= sqrt(x); i++)
        if (x % i == 0)
        {
            if (i != sqrt(x))
                data.push_back(i);
            data.push_back(x / i);
        }
    for (long long i = 1; i <= sqrt(y); i++)
        if (y % i == 0)
        {
            if (i != sqrt(y))
                data.push_back(i);
            data.push_back(y / i);
        }
    _sort(data, data.size());
    for (long long i = 0; i < data.size(); i++)
        if (data[i] == data[i + 1])
            cout << data[i] << " " << x / data[i] << " " << y / data[i] << endl;
}