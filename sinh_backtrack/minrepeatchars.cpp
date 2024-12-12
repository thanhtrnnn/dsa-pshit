#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02025
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define size(a)             (int)a.size()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.)edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

int countrepeat(string a, string b)
{
    int cnt = 0;
    for (char x : a)
    {
        for (char y : b)
            if (x == y)
                cnt++;
    }
    return cnt;
}

int n, res = 1e3;
vector<string> chains(15);
bool check[15] = {};
void backtrack(int cnt, int repeats, int pos)
{
    forup(i, 1, n + 1)
    {
        if (!check[i])
        {
            check[i] = true;
            if (cnt == n)
                res = min(res, repeats + countrepeat(chains[i], chains[pos]));
            else if (repeats < res && cnt < n)
                backtrack(cnt + 1, repeats + countrepeat(chains[i], chains[pos]), i);
            check[i] = false;
        }
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    forup(i, 1, n + 1)
        cin >> chains[i];
    backtrack(1, 0, 0);
    cout << res << el;
}