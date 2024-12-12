#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA08001
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


int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        queue<int> q;
        forup(i, 0, n)
        {
            int query; cin >> query;
            switch (query)
            {
                case 1:
                    cout << q.size() << el;
                    break;
                case 2:
                    (q.empty()) ? cout << "YES" : cout << "NO";
                    cout << el;
                    break;
                case 3:
                    int x; cin >> x;
                    q.push(x);
                    break;
                case 4:
                    if (!q.empty())
                        q.pop();
                    break;
                case 5:
                    (q.empty()) ? cout << "-1" : cout << q.front();
                    cout << el;
                    break;
                default:
                    (q.empty()) ? cout << "-1" : cout << q.back();
                    cout << el;
                    break;
            }
        }
    }
}