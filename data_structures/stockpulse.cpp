#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA07028
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
        vector<int> a(n + 1);
        stack<int> st;
        st.push(0); // buffer
        forup(i, 1, n + 1)
        {
            cin >> a[i];
            // trace back the start of "<= a[i]" sequence
            while (st.size() > 1 && a[st.top()] <= a[i])
                st.pop();
            // current pos - start
            cout << i - st.top() << " ";
            st.push(i);
        }
        cout << el;
    }
}