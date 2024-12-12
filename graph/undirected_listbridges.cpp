#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA09013
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

vector<int> adj[1001];
set<pair<int, int>> res;
int n, m;

void input()
{
	cin >> n >> m;
	forup(i, 0, m)
    {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

// A recursive function that finds and prints bridges using DFS traversal
// u, parent --> The vertex to be visited next & its parent
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] --> Stores parent vertices in DFS tree
int timer = 1;
void DFS(int u, vector<bool>& visited, vector<int>& disc, 
                                  vector<int>& low, int parent)
{
    visited[u] = true;
    // Initialize discovery time and low value
    disc[u] = low[u] = timer++;

    // Go through all vertices adjacent to this
    for (int v : adj[u])
    {
          // 1. If v is parent 
        if (v == parent)
            continue;

          // 2. If v is visited
        if (visited[v])
            low[u] = min(low[u], disc[v]);
      
          // 3. If v is not visited
        else {
            DFS(v, visited, disc, low, u);

            // update the low of u as it's quite possible 
            // a connection exists from v's descendants to u
            low[u] = min(low[u], low[v]);

            // if the lowest possible time to reach vertex v
            // is greater than discovery time of u it means 
            // that v can be only be reached by vertex above v
            // so if that edge is removed v can't be reached so it's a bridge
            if (low[v] > disc[u])
                res.insert({min(u, v), max(u, v)}); // no way from v to u except (v, u)
        }
    }
}

// DFS based function to find all bridges. It uses recursive function bridgeUtil()
void bridge(int V)
{
    // Mark all the vertices as not visited disc and low as -1
    vector<bool> visited (V + 1, false);
    vector<int> disc (V + 1, -1);
    vector<int> low (V + 1, -1);

    // Find Bridges in DFS tree rooted with vertex 'i'
    for (int i = 1; i <= V; i++)
        if (!visited[i])
            DFS(i, visited, disc, low, -1);
    
    for (auto x : res)
        cout << x.first << ' ' << x.second << ' ';
    res.clear();
}

int main()
{
    fileio();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	tests()
    {
		input();
        bridge(n);
        forup(i, 1, n + 1)
            adj[i].clear();
		cout << el;
	}
}