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
    switch (c)
    {
        case '+': case '-': case '*': case '/':
            return true;
        default:
            return false;
    }
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
        vector<string> a;
        forup(i, 0, n)
        {
            string x; cin >> x;
            a.push_back(x);
        }

        stack<ll> st;
        fordown(i, n - 1, 0)
        {
            //if (size(a[i]) != 1 || !isOperator(a[i][0]))
            if (isdigit(a[i].back()))
                st.push(stoll(a[i]));
            else {
                ll num1 = st.top(); st.pop();
                ll num2 = st.top(); st.pop();
                st.push(precalc(num1, num2, a[i][0]));
            }
        }
        cout << st.top() << el;
    }
}