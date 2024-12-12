#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11004
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
    node *left, *right;
    node(int neo): num(neo), left(NULL), right(NULL) {};
};

void addNodes(node *&tree, int u, int v, char c)
{
    if (!tree) // tree == NULL
    {
        tree = new node(u);
        node *sub = new node(v);
        if (c == 'L')
            tree->left = sub;
        else
            tree->right = sub;
    }
    else {
        if (tree->num == u)
        {
            node *sub = new node(v);
            if (c == 'L')
                tree->left = sub;
            else
                tree->right = sub;
        }
        else {
            if (tree->left)
                addNodes(tree->left, u, v, c);
            if (tree->right)
                addNodes(tree->right, u, v, c);
        }
    }
}

void levelOrder(node *tree)
{
    queue<node *> q;
    q.push(tree);
    while (!q.empty())
    {
        node *curr = q.front();
        cout << curr->num << ' ';
        q.pop();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    cout << el;
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
            addNodes(root, u, v, c);
        }
        levelOrder(root);
    }
} // for input like 10 20 L 10 30 R 20 40 L 20 60 R, which declares root first then sub