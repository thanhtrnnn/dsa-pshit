#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02045
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "; cout << el
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define size(a)             (int)a.size()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

vector<string> res;
int n;
string s;
void backtrack(int pos, string curr)
{
    if (size(curr))
        res.push_back(curr);
    forup(i, pos, n)
    {
        if (pos <= n)
            backtrack(i + 1, curr + s[i]);
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        cin >> n >> s;
        backtrack(0, "");

        sort(all(res));
        for (string x : res)
            cout << x << ' ';
        res.clear();
        cout << el;
    }
}