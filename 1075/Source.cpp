//https://programming.in.th/task/rev2_problem.php?pid=1075
#include <iostream>
#include <algorithm>
using namespace std;
struct _k
{
    int res, max;
};
struct k
{
    unsigned long long cost, work;
    double worth;
};
struct kk
{
    _k data;
    kk* next;
};
kk* newkk(int res, int max)
{
    kk* temp = new kk;
    temp->data.res = res;
    temp->data.max = max;

    temp->next = NULL;
    return temp;
}
bool x = false;
void inorder(kk* root)
{
    if (root->next != NULL and x == false)
    {
        inorder(root->next);
    }
    if (x == false)
        cout << root->data.res << " " << root->data.max;
    x = true;
}
kk* _push(kk** node, int res, int max)
{
    kk* temp = new kk;
    temp->data.res = res;
    temp->data.max = max;
    temp->next = *node;
    *node = temp;
}
kk* insert(kk* node, int res, int max)
{
    if (node == NULL)
    {
        return newkk(res, max);
    }
    node->next = insert(node->next, res, max);
    return node;
}

int fnmax(unsigned long long a, unsigned long long b)
{
    return (a > b) * a + (b >= a) * b;
}
bool comp(k& a, k& b)
{
    return a.worth > b.worth;
}
int main()
{
    kk* root = NULL;

    int n;
    cin >> n;
    k worm[n];
    double worthnow = 0, x = 0, y = 0;
    unsigned long long int res = 0, max = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> worm[i].work;
        cin >> worm[i].cost;
        double px = worm[i].work, py = worm[i].cost;
        worm[i].worth = px / py;
    }

    sort(worm, worm + n, comp);

    for (int i = 0; i < n; i++)
    {

        x = fnmax(max, worm[i].cost);
        y = res + worm[i].work;

        double px = x, py = y;
        if (worthnow < py / px)
        {
            max = fnmax(max, worm[i].cost);
            res += worm[i].work;
            double pres = res, pmax = max;
            worthnow = double(pres / pmax);

            if (i > 0 and root != NULL)
                insert(root, res, max);
            if (i == 0 or root == NULL)
                root = insert(root, res, max);
        }
    }
    inorder(root);
}