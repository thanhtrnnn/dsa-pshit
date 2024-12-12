#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11025
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

void avl_preorder(vector<int> a, int l, int r)
{
    if (l >= r) 
        return;
    int mid = (l + r) / 2;
    cout << a[mid] << ' ';
    avl_preorder(a, mid + 1, r);
    avl_preorder(a, l, mid);
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        vector<int> a(n);
        forup(i, 0, n) cin >> a[i];
        sort(all(a), greater<int>());
        avl_preorder(a, 0, n);
        cout << el;
    }
}