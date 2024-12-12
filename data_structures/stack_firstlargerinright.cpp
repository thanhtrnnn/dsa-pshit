#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA07027
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

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        vector<int> a(n), b(n, -1);
        stack<int> st;
        forup(i, 0, n) cin >> a[i];
        forup(i, 0, n)
        {
            // ramp down the array
            while (!st.empty() && a[i] > a[st.top()])
            {
                b[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        forup(i, 0, n)
        {
            (b[i] == -1) ? cout << -1 : cout << a[b[i]];
            cout << ' ';
        }
        cout << el;
    }
}