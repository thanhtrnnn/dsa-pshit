#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA07008
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

int priority_oprt(char c)
{
    switch (c)
    {
        case '^': case '%': // most prioritized
            return 1;
        case '*': case '/':
            return 2;
        case '+': case '-':
            return 3;
        default: // '(' least
            return 4;
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        string s; cin >> s;
        string res = "";
        stack<char> st;

        for (char c : s)
        {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                res += c;
            else if (c == '(')
                st.push(c);
            else if (c == ')') 
            {
				while (!st.empty() && st.top() != '(')
                {
					res += st.top(); // add oprt in parens to res
					st.pop();
				}
				st.pop(); // pop '('
			}
            else {
                // eg: c = '+', st.top() = '*'
                while (!st.empty() && priority_oprt(c) >= priority_oprt(st.top()))
                {
                    res += st.top(); // add the oprt with more priority to res
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty())
        {
            if (st.top() == '(')
                st.pop();
            else {
                res += st.top();
                st.pop();
            }
        }
        cout << res << el;
    }
}