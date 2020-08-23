//https://programming.in.th/task/rev2_problem.php?pid=1006
#include <iostream>
#include <string.h>
using namespace std;
struct kk
{
	int dc = 0;
};
template <typename T>
void sw(T& x, T& y)
{
	T v = x;
	x = y;
	y = v;
}
int dc(char c, kk data[])
{
	if (c == 'F')
	{
		sw(data[1], data[4]);
		sw(data[2], data[6]);
		sw(data[2], data[4]);
	}
	if (c == 'B')
	{
		sw(data[1], data[2]);
		sw(data[2], data[6]);
		sw(data[4], data[6]);
	}
	if (c == 'L')
	{
		sw(data[1], data[5]);
		sw(data[5], data[6]);
		sw(data[3], data[6]);
	}
	if (c == 'R')
	{
		sw(data[1], data[3]);
		sw(data[3], data[6]);
		sw(data[5], data[6]);
	}
	if (c == 'C')
	{
		sw(data[2], data[5]);
		sw(data[5], data[4]);
		sw(data[3], data[4]);
	}
	if (c == 'D')
	{
		sw(data[2], data[3]);
		sw(data[3], data[4]);
		sw(data[5], data[4]);
	}
}
int refill(kk dice[])
{
	for (int i = 1; i <= 6; i++)
		dice[i].dc = i;
	sw(dice[4], dice[5]);
}
int main()
{
	int n;
	cin >> n;
	char c[n + 1][1001];

	kk dice[8];
	for (int i = 0; i < n; i++)
	{

		refill(dice);
		scanf("%s", c[i]);
		int v = strlen(c[i]);
		for (int j = 0; j < v; j++)
		{
			dc(c[i][j], dice);
		}

		cout << dice[2].dc << " ";
	}
}