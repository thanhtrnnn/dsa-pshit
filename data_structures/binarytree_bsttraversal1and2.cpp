#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA011017, DSA11019
// pre to post
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

node *RotateLeft(node *T) 
{
    node *p = T; // p trỏ đến node gốc của cây
    if (!T || T->right == NULL)
        return NULL;
    else {
        p = T->right; //p trỏ đến cây con phải->gốc mới
        T->right = p ->left; // T trỏ đến node trái của p
        p->left = T; //Thiết lập liên kết trái cho p
    }
    return p;
}

void postOrder(node *tree)
{
    if (!tree) 
        return;
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->num << ' ';
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
        // root = RotateLeft(root);
        postOrder(root);
        cout << el;
    }
}