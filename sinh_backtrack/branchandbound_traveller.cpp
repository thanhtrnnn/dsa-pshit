#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02027
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define el                  "\n"

int n, price[105][105];
vector<int> sol, bestsol;
int current = 0, res = INT_MAX, min_unitprice = INT_MAX;
bool visited[105];

void input()
{
    cin >> n;
    forup(i, 1, n + 1)
    {
        forup(j, 1, n + 1)
        {
            cin >> price[i][j];
            if (price[i][j] != 0)
                min_unitprice = min(min_unitprice, price[i][j]);
        }
    }
    sol.resize(n + 1);
    memset(visited, false, sizeof(visited)); 
}

void backtrack(int pos)
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            sol[pos] = i;
            current += price[sol[pos - 1]][i]; // sol[pos - 1] -> sol[pos]

            if (pos == n)
            {
                if (res > current + price[sol[n]][1])
                {
                    bestsol = sol;
                    res = current + price[sol[n]][1]; // sol[n] -> 1
                }
            }
            // rule out the lower bound
            // assume travelling to other cities with min unit price
            else if (current + (n - pos + 1) * min_unitprice < res)
                backtrack(pos + 1);

            current -= price[sol[pos - 1]][i];
            visited[i] = false;
        }
    }
}

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

    input();
    sol[1] = 1;
    visited[1] = true;
    backtrack(2);
    cout << res << el;
    print(bestsol, 1, n + 1);
}