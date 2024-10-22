#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06013
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}


int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n, x; 
        cin >> n >> x;
        vector<int> a(n);
        int res = 0;
        forup(i, 0, n) 
        {
            cin >> a[i];
            if (a[i] == x)
                res++;
        }
        cout << ((res == 0) ? -1 : res) << el;
    }
}