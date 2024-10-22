#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA07002
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

    stack<int> st;
    int n; cin >> n;
    forup(i, 0, n)
    {
        string s; cin >> s;
        if (s == "PUSH")
        {
            int n; cin >> n;
            st.push(n);
        }
        if (!st.empty() && s == "POP")
            st.pop();
        if (s == "PRINT")
        {
            (st.empty()) ? cout << "NONE" << el
                        : cout << st.top() << el;
        }
    }
}