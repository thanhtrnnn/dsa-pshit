#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA07016
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
        string s; cin >> s;
        s += 'I';
        stack<int> st;
        forup(i, 1, (int)s.length() + 1)
        {
            if (s[i - 1] == 'I')
            {
                cout << i;
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
            }
            else
                st.push(i);
        }
        cout << el;
    }
}