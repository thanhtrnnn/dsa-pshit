#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA011022
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

void addNode(node *&tree, int x)
{
    if (!tree)
    {
        tree = new node(x);
        return;
    }
    (x < tree->num) ? addNode(tree->left, x) 
                    : addNode(tree->right, x);

}

int countLeaves(node *tree)
{
    if (!tree)
        return 0;
    if (!tree->left && !tree->right)
        return 1;
    else
        return countLeaves(tree->left) + countLeaves(tree->right);
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
            int x; cin >> x;
            addNode(root, x);
        }
        cout << n - countLeaves(root) << el;
    }
}