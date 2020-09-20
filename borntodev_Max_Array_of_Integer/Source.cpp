//https://www.borntodev.com/grader/?quizNo=336
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int x, int y)
{
    return x > y;
}
int main()
{
    string c;
    vector<int> data;
    int num;
    getline(cin, c);
    int l = c.size();
    for (int i = 0; i < l; i++)
    {
        num = 0;
        while (c[i] >= '0' and c[i] <= '9')
        {
            num *= 10;
            num += c[i] - '0';
            i++;
        }
        data.push_back(num);
    }
    sort(data.begin(), data.end(), comp);
    cout << data[0];
}