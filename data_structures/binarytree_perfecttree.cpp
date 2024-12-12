#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11010
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

unordered_set<int> s;
int treesize = 0;
bool isLeavesSamelevel(node *tree, int ref)
{
    node *ptr = tree;
    // ++treesize;
    if (ptr->left && !ptr->right || !ptr->left && ptr->right)
        return false;
    if (!ptr->left && !ptr->right)
    {
        if (!s.size())
            s.insert(ref);
        else if (s.insert(ref).second) // true when new elem inserted
            return false;
    }
    else {
        if (ptr->left && !isLeavesSamelevel(ptr->left, ref + 1))
            return false;
        if (ptr->right && !isLeavesSamelevel(ptr->right, ref + 1))
            return false;
    }
    return true;
}

bool isAllTwoLeaves(int n)
{
    int neo = 1;
    while (neo < n)
        neo *= 2;
    return neo == n + 1;
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
        s.clear();
        treesize = 0;
        // (isLeavesSamelevel(root, 0) && isAllTwoLeaves(treesize)) ? cout << "Yes" << el
        //                                                  : cout << "No" << el;
        (isLeavesSamelevel(root, 0)) ? cout << "Yes" << el
                                    : cout << "No" << el;
    }
}