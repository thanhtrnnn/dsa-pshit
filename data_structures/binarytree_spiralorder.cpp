#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11006
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

void spiralOrder(node *tree)
{
    stack<node *> s1, s2;
    s1.push(tree);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            node *curr = s1.top();
            s1.pop();
            cout << curr->num << ' ';
            if (curr->right)
                s2.push(curr->right);
            if (curr->left)
                s2.push(curr->left);
        }
        while (!s2.empty()) 
        {
            node *curr = s2.top();
            s2.pop();
            cout << curr->num << ' ';
            if (curr->left)
                s1.push(curr->left);
            if (curr->right)
                s1.push(curr->right);
        }
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
            addNode(root, u, v, c);
        }
        spiralOrder(root);
    }
}