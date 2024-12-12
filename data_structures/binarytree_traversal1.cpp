#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11003
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

int search(int *in, int n, int x)
{
    forup(i, 0, n)
        if (in[i] == x)
            return i;
    return -1;
}

void traverse(int in[], int pre[], int n) // post: left-right-node
{
    // position of pre[i] in in
    int pos = find(in, in + n, pre[0]) - in;
    if (pos != 0)
        // go down 1 level by pre -> print LEFT, finally *pre = *in 
        traverse(in, pre + 1, pos);
    if (pos != n - 1)
        // *in = left, *pre = node -> print RIGHT
        traverse(in + pos + 1, pre + pos + 1, n - pos - 1);
    // print NODE
    cout << pre[0] << " ";
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        // in: left-node-right, pre: node-left-right
        int in[n], pre[n];
        forup(i, 0, n) cin >> in[i];
        forup(i, 0, n) cin >> pre[i];
        traverse(in, pre, n); // n is number of nodes in curr branch
        cout << el;
    }
}