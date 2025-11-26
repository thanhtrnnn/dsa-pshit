#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA09016, DSA09015
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

vector<int> adj[1005];
vector<bool> visited(1005);
vector<int> pre(1005);
void dfs(int u, bool &found) 
{
	visited[u] = true;
	for (int v : adj[u]) 
	{
		if (!visited[v]) 
		{
			pre[v] = u;
			dfs(v, found);
		}
		// v is adj to u, v is not prev to u -> back to the start
		else if (pre[v] == 0)
		{
			found = 1;
			break;
		}
	}
}
bool containsCircuit(int nodes) 
{
	bool found = 0;
	for (int i = 1; i <= nodes; i++) 
	{
		fill(all(visited), false);
		fill(all(pre), 0);
		dfs(i, found);
		if (found) 
			return true;
	}
	return false;
}

int main()
{
    fileio();
	tests()
    {
		fill(all(visited), false);
		for (int i = 0; i < 1001; i++)
            adj[i].clear();

		int n, m; 
        cin >> n >> m;
		forup(i, 0, m)
        {
			int u, v; 
            cin >> u >> v;
			adj[u].push_back(v);
		}

		cout << (containsCircuit(n) ? "YES" : "NO") << el;
	}
}
