#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA9012, DSA09018
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

vector<int> a[1001];
vector<bool> visited(1001);
void DFS(int u) 
{
	visited[u] = true;
	for (int x : a[u]) 
		if (!visited[x]) 
			DFS(x);
}

int main()
{
    fileio();
	int t; cin >> t;
	while (t--) 
    {
		fill(all(visited), false);
		for (int i = 0; i < 1001; i++)
            a[i].clear();

		int n, m; 
        cin >> n >> m;
		for (int i = 0; i < m; i++) 
        {
			int u, v; 
            cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}

		int conn = 0; // original connected comps
		for (int i = 1; i <= n; i++) 
        {
			if (!visited[i]) 
            {
				conn++;
				DFS(i);
			}
		}
		for (int i = 1; i <= n; i++) 
        {
			int neoconn = 0;
			fill(all(visited), false);
			visited[i] = true; // rule out the i
			for (int j = 1; j <= n; j++) 
            {
				if (!visited[j]) 
				{
					neoconn++;
					DFS(j);
				}
			}
			if (neoconn > conn) // connected comps increase
                cout << i << " ";
		}
		cout << el;
	}
}
