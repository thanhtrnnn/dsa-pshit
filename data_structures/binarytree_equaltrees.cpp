#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11012
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

bool isTreesEqual(node *tree1, node *tree2)
{
    node *p1 = tree1, *p2 = tree2;
    if (p1 && p2)
    {
        if (p1->num != p2->num)
            return false;
        else {
            if (!isTreesEqual(p1->left, p2->left))
                return false;
            if (!isTreesEqual(p1->right, p2->right))  
                return false;
        }
    }
    return true;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n1; cin >> n1;
        node *root1 = NULL;
        forup(i, 0, n1)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            addNode(root1, u, v, c);
        }
        int n2; cin >> n2;
        node *root2 = NULL;
        forup(i, 0, n2)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            addNode(root2, u, v, c);
        }
        cout << isTreesEqual(root1, root2) << el;
    }
}