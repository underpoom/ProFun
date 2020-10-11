//https://projecteuler.net/problem=29
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int root(int x, int exp, int data[])
{
    for (int i = 2; i <= 101; i++)
    {
        while (x % i == 0)
        {
            data[i]++;
            x /= i;
        }
    }
    for (int i = 1; i <= 101; i++)
    {
        if (data[i] > 0)
        {
            data[i] *= exp;
        }
    }
}
string int_to_str(int n)
{
    stringstream cc;
    cc << n;
    return cc.str();
}
string arr_to_str(int data[])
{
    string s = "";
    for (int i = 1; i <= 101; i++)
    {
        s += int_to_str(data[i]);
    }
    return s;
}
int main()
{
    vector<string> res;
    vector<string>::iterator it; //this is a pointer
    int n = 0;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 2; j <= 100; j++)
        {
            int data[105] = {}, base, exp;
            base = i, exp = j;
            root(base, exp, data);
            string s = arr_to_str(data);

            res.push_back(s);
        }
    }
    sort(res.begin(), res.end());
    it = unique(res.begin(), res.end());
    res.resize(distance(res.begin(), it));

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    cout << res.size() + 9;
}
