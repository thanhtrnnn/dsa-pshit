#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
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

bool isEnough(string s) // only applied to valid string
{
    int cnt1 = 0; // cnt2 = 0;
    stack<char> st;
    for (char c : s)
    {
        if (c == '+' || c == '-')
            cnt1++;
        else if (c == '(')
            st.push(c); // cnt++;
    }
    return cnt1 == (int)st.size(); // cnt1 == cnt2;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        (!isEnough(s)) ? cout << "Yes" << el
                    : cout << "No" << el;
    }
}