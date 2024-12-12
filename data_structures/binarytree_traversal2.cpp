#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11005
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

void addNode(node *&T, int *in, int *level, int n) 
{
	T = new node(level[0]); // build
    // < k -> left, > k -> right
	int k = find(in, in + n, level[0]) - in;
	int L[n], R[n], l = 0, r = 0; // left & right subtrees
	for (int i = 1; i < n; i++)
    {
		if (find(in, in + n, level[i]) - in < k)
            L[l++] = level[i];
		else 
            R[r++] = level[i];
    }
	if (k > 0) // anything to the left
        addNode(T->left, in, L, k);
	if (n - k - 1 > 0)  // anything to the right
        addNode(T->right, in + k + 1, R, n - k - 1);
}

void postOrder(node *tree)
{
    if (tree)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->num << ' ';
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        int in[n], level[n];
        forup(i, 0, n) cin >> in[i];
        forup(i, 0, n) cin >> level[i];
        node *root = NULL;
        addNode(root, in, level, n);
        postOrder(root);
        cout << el;
    }
}