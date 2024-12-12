#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "; cout << el
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define size(a)             (int)a.size()
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

void levelOrder(node *&tree)
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

void postOrder(node *&tree)
{
    if (!tree) 
        return;
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->num << ' ';
}

// min node
node *find(node *&root)
{
    while (root->left) 
        root = root->left;
    return root;
}

// refer to _ref
void deleteNode(node *&tree, int x)
{
    if (x < tree->num) 
        deleteNode(tree->left, x);
    else if (x > tree->num) 
        deleteNode(tree->right, x);

    else {
        if (!tree->left)
        {
            tree = tree->right;
            return;
        }
        if (!tree->right)
        {
            tree = tree->left;
            return;
        }

        node *target = find(tree->right);
        tree->num = target->num;
        deleteNode(tree->right, target->num);
    }
}


int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; 
    cin >> n >> q;
    node *root = NULL;
    forup(i, 0, n)
    {
        int x; cin >> x;
        addNode(root, x);
    }
    cout << "BST: ";
    levelOrder(root);
    
    forup(i, 1, q + 1)
    {
        string opr;
        int x;
        cin >> opr >> x;
        (opr == "ins") ? addNode(root, x)
                        : deleteNode(root, x);

        cout << "Query #" << i << ": ";
        postOrder(root);
        cout << el;
    }
}