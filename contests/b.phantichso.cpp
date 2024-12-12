#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
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


int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        queue<int> q;
        set<int> visited;
        q.push(n);
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            for (int u = 1; u <= sqrt(top); u++)
            {
                // u <= v
                if (top % u == 0)
                {
                    int v = top / u;
                    int neo = (u - 1) * (v + 1);
                    if (!visited.count(neo))
                    {
                        visited.insert(neo);
                        q.push(neo);
                    }
                }
            }
        }

        cout << size(visited) << el;
        for (int x : visited)
            cout << x << ' ';
        cout << el;
    }
}