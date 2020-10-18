//https://programming.in.th/task/rev2_problem.php?pid=1056
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

int main()
{
    int Qs[1002] = {}, k;
    kk* root = NULL;
    int n, x;
    cin >> n >> k;
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

    int v = 0, res = 0;
    for (int i = 1001; i > 0; i--)
    {
        while (Qs[i] != 0)
        {

            Qs[i]--;
            if (v % k == 0)
                res += i;
            v++;
        }
    }
    cout << res;
}
