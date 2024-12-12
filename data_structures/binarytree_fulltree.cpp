#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11011
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

struct node
{
    int num;
    struct node *left, *right;
    node(int neo): num(neo), left(NULL), right(NULL) {};
};

void addNode(node *&tree, int u, int v, char c)
{
    if (!tree)
    {
        tree = new node(u);
        node *sub = new node(v);
        (c == 'L') ? tree->left = sub : tree->right = sub;
    }
    else {
        if (tree->num == u)
        {
            node *sub = new node(v);
            (c == 'L') ? tree->left = sub : tree->right = sub;
        }
        else {
            if (tree->left) 
                addNode(tree->left, u, v, c);
            if (tree->right)
                addNode(tree->right, u, v, c);
        }
    }
}

bool isAllTwoLeaves(node *tree)
{
    node *ptr = tree;
    if (ptr->left && !ptr->right || !ptr->left && ptr->right)
        return false;
    else {
        if (ptr->left && !isAllTwoLeaves(ptr->left))
            return false;
        if (ptr->right && !isAllTwoLeaves(ptr->right))
            return false;
    }
    return true;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        node *root = NULL;
        forup(i, 0, n)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            addNode(root, u, v, c);
        }
        cout << isAllTwoLeaves(root) << el;
    }
}