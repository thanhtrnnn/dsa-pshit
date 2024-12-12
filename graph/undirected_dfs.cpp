#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA09004
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

vector<int> adj[1001]; //casiditj
vector<bool> visited(1001);
int n, m, start;

void DFS(int u)
{
	cout << u << " ";
	visited[u] = true;
	for (int v : adj[u])
		if (!visited[v])
			DFS(v);
}

void input()
{
	cin >> n >> m >> start;
	forup(i, 0, m)
    {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	fill(all(visited), false);
}

int main()
{
    fileio();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	tests()
    {
		input();
		DFS(start);
        forup(i, 1, n + 1)
            adj[i].clear();
		cout << el;
	}
}