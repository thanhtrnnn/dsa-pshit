#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11002
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

bool isOperator(string c)
{
    return c == "+" || c == "-" || c == "*" || c == "/";
}

int calc(int i, vector<string> &s)
{
    if (s[i] == "+") 
        return calc(i * 2 + 1, s) + calc(i * 2 + 2, s);
    else if (s[i] == "-") 
        return calc(i * 2 + 1, s) - calc(i * 2 + 2, s);
    else if (s[i] == "*") 
        return calc(i * 2 + 1, s) * calc(i * 2 + 2, s);
    else if (s[i] == "/") 
        return calc(i * 2 + 1, s) / calc(i * 2 + 2, s);
	else 
        return stoi(s[i]);
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        vector<string> tree(2 * n);
        int cur = 0;
        forup(i, 0, n) 
        {
            string s; cin >> s;
            if (i == 0 || isOperator(tree[(i - 1) / 2]))
                tree[cur++] = s;
            else {
                while (!isOperator(tree[(cur - 1) / 2]))
                    cur++;
                tree[cur++] = s;                
            }
        }
        cout << calc(0, tree) << el;
    }
}