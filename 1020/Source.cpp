//https://programming.in.th/task/rev2_problem.php?pid=1020
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <limits>
#include <algorithm>
using namespace std;
int ques(int p1, int p2)
{
    if (p1 == 1 && p2 == 1)
        cout << "Double Palindrome";
    else if (p1 == 1)
        cout << "Palindrome";
    else
        cout << "No";
}

main()
{
    char* c = new char[201];
    cin >> c;
    int l = strlen(c);
    char* c1 = c;
    int p1 = 1, p2 = 1;
    for (; *c1 != '\0'; c1++)
        *c1 = toupper(*c1);
    c1 -= strlen(c);
    for (int i = 0; i < l / 4; i++)
        if (*(c1 + i) != *(c1 + l / 2 - i - 1))
            p2 = 0;
    for (int i = 0; i <= strlen(c) / 2; i++)
        if (*(c1 + i) != *(c1 + strlen(c) - i - 1))
            p1 = 0;
    ques(p1, p2);

}