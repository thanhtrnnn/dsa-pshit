#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA9001
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

void display_graph(const vector<vector<int>>& adj, int nodes) 
{
    for (int i = 1; i <= nodes; i++) 
    {
        cout << i << ":";
        for (int j : adj[i]) 
            cout << " " << j;
        cout << endl;
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int nodes, edges;
        cin >> nodes >> edges;  // Read number of nodes and edges

        vector<vector<int>> adj(nodes + 1);  // Initialize adjacency list
        for (int i = 0; i < edges; i++) 
        {
            int u, v;
            cin >> u >> v;  // Read each edge
            adj[u].push_back(v);  // Add edge from u to v
            adj[v].push_back(u);  // Add edge from v to u
        }

        display_graph(adj, nodes);  // Display adjacency list
    }

    return 0;
}
