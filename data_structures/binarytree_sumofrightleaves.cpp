#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11014
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

// not so random, first node is the root
void addRandomNodes(node *&tree, int n)
{
	map<int, node *> m;
	for (int i = 0; i < n; i++)
	{
		int u, v;
		char c;
		cin >> u >> v >> c;
		if (!m[u])
		{
			tree = new node(u);
			if (c == 'L')
			{
				tree->left = new node(v);
				m[v] = tree->left;
			}
			else {
				tree->right = new node(v);
				m[v] = tree->right;
			}
			m[u] = tree;
		}
		else {
			if (c == 'L')
			{
				m[u]->left = new node(v);
				m[v] = m[u]->left;
			}
			else {
				m[u]->right = new node(v);
				m[v] = m[u]->right;
			}
		}
	}
}

int sumofRightLeaves(node *tree, int rightleaf)
{
    if (!tree)
        return 0;
    if (!tree->left && !tree->right && rightleaf)
        return tree->num;
    else 
        return sumofRightLeaves(tree->left, 0) + sumofRightLeaves(tree->right, 1);
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        node *root = NULL;
        addRandomNodes(root, n);
        cout << sumofRightLeaves(root, 0) << el;
    }
}