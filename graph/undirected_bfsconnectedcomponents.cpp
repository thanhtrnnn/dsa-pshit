#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA09009
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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    tests()
    {
        int nodes, edges;
        cin >> nodes >> edges;
        vector<vector<int>> adj(nodes + 5);
        forup(i, 0, edges)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); 
            adj[v].push_back(u);
        }

        int res = 0;
        vector<bool> visited(nodes + 1, false);
        forup(i, 1, nodes + 1)
        {
            if (!visited[i])
            {
                ++res;
                visited[i] = true;
                queue<int> q;
                q.push(i);
                
                while (!q.empty())
                {
                    int top = q.front();
                    q.pop();
                    for (int v : adj[top])
                    {
                        if (!visited[v])
                        {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }

        cout << res << el;
    }

    return 0;
}
