//https://programming.in.th/task/rev2_problem.php?pid=1042
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
struct kk
{
    int data;
    kk* next;
};
kk* newkk(int data)
{
    kk* temp = new kk;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int mx = 0;
int inorder(kk* root)
{
    if (root != NULL)
    {
        mx = max(mx, root->data);
        inorder(root->next);

    }
    return mx;

}
kk* _push(kk** node, int data)
{
    kk* temp = new kk;
    temp->data = data;
    temp->next = *node;
    *node = temp;
}
kk* insert(kk* node, int data)
{
    if (node == NULL)
    {

        return newkk(data);
    }

    node->next = insert(node->next, data);

    return node;
}
int max(int x, int y)
{
    return (x > y) * x + (y >= x) * y;
}
int min(int x, int y)
{
    return (x > y) * y + (y >= x) * x;
}
int main()
{
    kk* root = NULL;
    int ms = 5001;
    int row[ms] = {}, column[ms] = {};
    int n, x, y, r, _x, _y;
    cin >> _x >> _y >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> r;
        for (int j = max(x - r, 0); j <= min(x + r, ms); j++)
            column[j]++;

        for (int j = max(y - r, 0); j <= min(y + r, ms); j++)
            row[j]++;
    }

    for (int i = 0; i < ms; i++)
    {

        if (i > 0 and root != NULL)
        {
            insert(root, row[i]);
            insert(root, column[i]);
        }

        if (i == 0 or root == NULL)
        {
            root = insert(root, row[i]);
            insert(root, column[i]);
        }

    }
    cout << inorder(root);

}