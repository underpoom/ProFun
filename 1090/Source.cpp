https://programming.in.th/task/rev2_problem.php?pid=1090
#include <iostream>
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
void inorder(kk* root)
{
    if (root != NULL)
    {
        cout << root->data;
        inorder(root->next);
    }
}
kk* _push(kk** node, int data)
{
    kk* temp = new kk;
    temp->data = data;
    temp->next = *node;
    *node = temp;
}
kk* insert(kk* node, int data, int Qs[])
{
    if (node == NULL)
        return newkk(data);
    node->next = insert(node->next, data, Qs);

    return node;
}

int Qs[2000001] = {}, k;
int main()
{

    kk* root = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (i == 0)
            root = insert(root, x, Qs);
        else
            insert(root, x, Qs);
    }
    while (root != NULL)
    {
        Qs[root->data]++;
        root = root->next;
    }

    long long re = 0;
    int a;
    cin >> a;

    int ch;
    for (int i = 0; i <= a / 2; i++)
    {

        if (a - i == i)
            re += (Qs[i] * (Qs[i] - 1)) / 2;
        else
            re += (Qs[i]) * (Qs[a - i]);
    }
    cout << re;
}
