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

string Try(int n)
{
    queue<string> q;
    q.push("1");
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        if (stoll(s) % n == 0)
            return s;
        q.push(s + "0");
        q.push(s + "1");
    }
    return "0";
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        cout << Try(n) << el;
    }
}