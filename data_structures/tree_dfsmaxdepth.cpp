#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11028
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

vector<int> adj[100001];
vector<bool> visited(100001);
int n, res;

void DFS(int u, int cnt)
{
	res = max(res, cnt);
	visited[u] = true;
	for (int v : adj[u])
		if (!visited[v])
			DFS(v, cnt + 1);
}

void input()
{
	cin >> n;
	forup(i, 0, n - 1)
    {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
}

int main()
{
    fileio();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	tests()
    {
        res = 0;
        forup(i, 0, 100001)
        {
            adj[i].clear();
            visited[i] = false;
        }
		input();
		DFS(1, 0);
        
		cout << res << el;
	}
}