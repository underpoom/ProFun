//https://programming.in.th/task/rev2_problem.php?pid=1027
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
struct kk
{
    char c;
    int p = 0;
};

void _swap(kk& x, kk& y)
{
    kk t = x;
    x = y;
    y = t;
}
int _sort(kk data[], int live)
{

    int v = 0;
    for (int i = live - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j].p < data[j + 1].p)
                _swap(data[j], data[j + 1]);
        }
    }
}
int main()
{
    kk data[8 + 1];
    int live = 7;
    int still = 7;
    for (int i = 0; i < 7; i++)
        data[i].c = char('A' + i);
    string k = "0";
    int pl = 6;
    while (k[0] != '!')
    {
        cin >> k;
        if (k[0] == '!')
            break;
        for (int i = 0; i < k.size(); i++)
        {
            int v = k[i] - 'A';
            if (data[v].p != -1)
                data[v].p++;
        }
        if (still != 1)
        {

            int min = 2e10, v = 0;
            for (int i = 0; i < live; i++)
                if (data[i].p < min and data[i].p != -1)
                    min = data[i].p;
            for (int i = 0; i < live; i++)
                if (data[i].p == min)
                    v++;
            if (v == 1)
                for (int i = 0; i < live; i++)
                    if (data[i].p == min)
                    {
                        data[i].p = -1;
                        still--;
                    }
        }
    }
skip:;

    _sort(data, live);

    int v = 0;
    for (int i = 0; i < 7; i++)
        if (data[i].p != -1)
            v++;
    cout << v << endl;
    for (int i = 0; i < live; i++)
        if (data[i].p != -1)
            cout << data[i].c << " " << data[i].p << endl;
}