//https://programming.in.th/task/rev2_problem.php?pid=1070
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
    {
        Qs[data]++;
        return newkk(data);
    }

    node->next = insert(node->next, data, Qs);

    return node;
}
void qs(int data[])
{
    int n = 100001;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++)
        if (data[i] != 0)
        {
            a = i;
            data[i]--;
            break;
        }
    for (int i = 0; i < n; i++)
        if (data[i] != 0)
        {
            b = i;
            data[i]--;
            break;
        }
    for (int i = n - 1; i >= 0; i--)
        if (data[i] != 0)
        {
            c = i;
            break;
        }


    if (c < a + b)
        cout << "no";
    else
        cout << "yes";

}

int main()
{

    int Qs[100001] = {}, k;
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

    qs(Qs);
}