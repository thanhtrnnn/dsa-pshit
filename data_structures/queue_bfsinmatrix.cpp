#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA08021
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

struct position
{
    int x, y, moves;
};

vector<int> a[1001];
bool visited[1001][1001] = {};
void BFS(int m, int n)
{
    queue<position> q;
    q.push({1, 1, 0});
    visited[1][1] = true;
    int res = 1e7;
    while (!q.empty())
    {
        position curr = q.front();
        q.pop();

        if (curr.x == m && curr.y == n)
        {
            res = min(res, curr.moves);
            break;
        }
        if (curr.x > m || curr.y > n || curr.moves > res)
            continue;
        
        if (!visited[curr.x][curr.y + a[curr.x][curr.y]])
        {
            visited[curr.x][curr.y + a[curr.x][curr.y]] = true;
            q.push({curr.x, curr.y + a[curr.x][curr.y], curr.moves + 1});
        }
        if (!visited[curr.x + a[curr.x][curr.y]][curr.y])
        {
            visited[curr.x + a[curr.x][curr.y]][curr.y] = true;
            q.push({curr.x + a[curr.x][curr.y], curr.y, curr.moves + 1});
        }
    }
        
    cout << ((res == 1e7) ? -1 : res) << el;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int m, n;
        cin >> m >> n;
        forup(i, 1, m + 1)
        {
            a[i].resize(n + 1);
            forup(j, 1, n + 1)
                cin >> a[i][j];
        }

        BFS(m, n);
        memset(visited, false, sizeof(visited));
    }
}