#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA07012
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

bool isOperator(char c)
{
    switch (c)
    {
        case '+': case '-': case '*': case '/':
            return true;
        default:
            return false;
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        string s; cin >> s;
        stack<string> st;
        for (char c : s)
        {
            if (!isOperator(c))
                st.push(string(1, c));
            else {
                string s1 = st.top(); st.pop();
                string s2 = st.top(); st.pop();
                st.push('(' + s2 + c + s1 + ')');
            }
        }
        cout << st.top() << el;
    }
}