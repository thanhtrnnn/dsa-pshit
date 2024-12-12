#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA09008
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

void dfs(int u, vector<vector<int>> adj, vector<bool> &visited)
{
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs(v, adj, visited);
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int nodes, edges;
        vector<vector<int>> adj(nodes + 5);
        vector<bool> visited(nodes + 5); // intentional due to oj's error
        cin >> nodes >> edges;
        forup(i, 0, edges)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int conn = 0;
        forup(i, 1, nodes + 1)
        {
            if (!visited[i])
            {
                conn++;
                dfs(i, adj, visited);
            }
        }

        cout << conn << el;
    }
}