#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA01024, DSA02023
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

vector<string> s(50), cur;
void backtrack(int pos, int cnt, int n, int k)
{
    if (cnt == k)
    {
        print(cur, 0, k);
        cout << el;
        return;
    }
    for (int i = pos; i < n; i++)
    {
        cur.push_back(s[i]);
        backtrack(i + 1, cnt + 1, n, k);
        cur.pop_back();
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);
 
    int n, k;
    cin >> n >> k;
    forup(i, 0, n) cin >> s[i];
    sort(all(s));
    s.erase(unique(all(s)), s.end());
    if (s[0] == "")
        s.erase(s.begin(), s.begin() + 1);
    n = s.size();
    backtrack(0, 0, n, k);
}