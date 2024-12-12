#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11024
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

// An AVL tree node 
struct node 
{ 
    int num; 
    node *left, *right; 
    int height;

    node(int k) 
    { 
        num = k; 
        left = right = NULL; 
        height = 1; 
    }
}; 

int height(node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 

// A utility function to right rotate subtree rooted with y 
void rightRotate(node *&y) 
{ 
    node *x = y->left; 
    node *T2 = x->right; 

    // Perform rotation 
    x->right = y; 
    y->left = T2; 

    // Update heights 
    y->height = 1 + max(height(y->left), height(y->right)); 
    x->height = 1 + max(height(x->left), height(x->right)); 

    y = x;
} 

// A utility function to left rotate subtree rooted with x 
void leftRotate(node *&x) 
{ 
    node *y = x->right; 
    node *T2 = y->left; 

    // Perform rotation 
    y->left = x; 
    x->right = T2; 

    // Update heights 
    x->height = 1 + max(height(x->left), height(x->right)); 
    y->height = 1 + max(height(y->left), height(y->right)); 

    x = y;
} 

// Get balance factor of node N 
int getBalance(node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

// Recursive function to insert a num in the subtree rooted with node 
void insert(node *&tree, int num) 
{ 
    // Perform the normal BST insertion
    if (tree == NULL) 
        tree = new node(num); 

    if (num < tree->num) 
        insert(tree->left, num); 
    else if (num > tree->num) 
        insert(tree->right, num); 
    else // Equal keys are not allowed in BST 
        return; 

    // Update height & get the balance factor of this ancestor tree 
    tree->height = 1 + max(height(tree->left), height(tree->right)); 
    int balance = getBalance(tree);

    // If unbalanced (abs(balance) > 1), then there are 4 cases 
    // Left Left Case 
    if (balance > 1 && num < tree->left->num) 
        rightRotate(tree); 

    // Right Right Case 
    if (balance < -1 && num > tree->right->num) 
        leftRotate(tree); 

    // Left Right Case 
    if (balance > 1 && num > tree->left->num) 
    { 
        leftRotate(tree->left); 
        rightRotate(tree); 
    } 

    // Right Left Case 
    if (balance < -1 && num < tree->right->num) 
    { 
        rightRotate(tree->right); 
        leftRotate(tree); 
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        node *root = NULL;
        vector<int> a;
        forup(i, 0, n)
        {
            int x; cin >> x;
            a.push_back(x);
            // insert(root, x);
        }
        // cout << root->num << el;
        sort(all(a));
        cout << a[(n - 1) / 2] << el;
    }
}