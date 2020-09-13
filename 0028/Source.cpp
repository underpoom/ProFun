//https://programming.in.th/task/rev2_problem.php?pid=0028
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct kk
{
    string k;
    int score = 0;
    int goaled = 0;
    int goals = 0;
};
bool comp(kk& x, kk& y)
{
    return x.score > y.score;
}
bool comp2(kk& x, kk& y)
{
    if (x.score == y.score)
        return x.goaled > y.goaled;
    else return 0;
}

bool comp3(kk& x, kk& y)
{
    if (x.score == y.score and x.goaled == y.goaled)
        return x.goals > y.goals;
    else return 0;
}

int main()
{
    kk team[4];
    int data[5][5];
    for (int i = 0; i < 4; i++)
        cin >> team[i].k;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> data[i][j];

    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 4; j++)
        {
            if (data[i][j] > data[j][i])
                team[i].score += 3;
            else if (data[i][j] < data[j][i])
                team[j].score += 3;
            else
            {
                team[i].score += 1;
                team[j].score += 1;
            }

            team[i].goals += data[i][j];
            team[j].goals += data[j][i];
            team[i].goaled += data[i][j] - data[j][i];
            team[j].goaled += data[j][i] - data[i][j];
        }
    sort(team, team + 4, comp);
    sort(team, team + 4, comp2);
    sort(team, team + 4, comp3);

    for (int i = 0; i < 4; i++)
        cout << team[i].k << " " << team[i].score << endl;

}