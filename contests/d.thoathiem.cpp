#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "; cout << el
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define maxn                (int)(1e5 + 7)
#define size(a)             (int)a.size()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

vector<int> res(maxn, mod); // min times to reach exit
vector<int> adj[maxn];
vector<bool> isExit(maxn);

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front(); 
        q.pop();
        for (int &v : adj[u])
        {
            // phòng v không phải lối thoát và
            // cách đi này tốn ít thời gian hơn các cách trước
            if (!isExit[v] && res[u] + 1 < res[v])
            {
                res[v] = res[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    forup(i, 0, k)
    {
        int room; cin >> room;
        res[room] = 0; // takes no time
        isExit[room] = true;
    }

    int edges; cin >> edges;
    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    forup(i, 1, n + 1)
        if (isExit[i])
            bfs(i); // spread from exit to calc each room
    print(res, 1, n + 1);
}
