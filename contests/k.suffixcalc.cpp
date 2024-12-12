#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    return c == '+' || c == '-' || c == '*' || c == '/';
}

ll precalc(ll a, ll b, int opr)
{
    switch (opr)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return a / b;
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        cin.ignore();
        string s, buf;
        stack<ll> st;
        vector<string> a;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> buf)
            a.push_back(buf);
        
        forup(i, 0, n)
        {
            if (size(a[i]) != 1 || !isOperator(a[i][0]))
                st.push(stoll(a[i]));
            else {
                ll num1 = st.top(); st.pop();
                ll num2 = st.top(); st.pop();
                st.push(precalc(num2, num1, a[i][0]));
            }
        }
        cout << st.top() << el;
    }
}