#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA09005
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
vector<bool> visited(1001);
int n, m, start;
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while (!q.empty())
    {
        int curr = q.front();
        cout << curr << ' ';
        q.pop();

        for (int v : adj[curr])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }                
    }
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
        BFS(start);
        forup(i, 1, n + 1)
            adj[i].clear();
		cout << el;
	}
}