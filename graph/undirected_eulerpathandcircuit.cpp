#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA10004
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

int n, m, adj[1001][1001] = {};
vector<int> adja[1001];
void input()
{
	cin >> n >> m;
    forup(i, 1, n + 1)
        adja[i].clear();
	forup(i, 0, m)
    {
		int x, y;
		cin >> x >> y;
		// adj[x][y] = adj[y][x] = 1;
        adja[x].push_back(y);
        adja[y].push_back(x);
	}
}

int isEuler() 
{
    int evens = 0, odds = 0;
    forup(u, 1, n + 1)
    {
        // int row = 0;
        // forup(v, 1, n + 1)
        //     row += adj[u][v];
        // (row % 2 == 0) ? evens++ : odds++;
        if (size(adja[u]))
            (size(adja[u]) % 2) ? odds++ : evens++;
    }
    if (evens == n) 
        return 2; // nếu tất cả các đỉnh đều có bậc chẵn -> chu trinh
    else if (odds == 2) 
        return 1; // nếu chỉ có hai đỉnh bậc lẻ -> duong di
    return 0;
}

int main()
{
    fileio();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	tests()
    {
		input();
        cout << isEuler() << el;
        // memset(adj, 0, sizeof(adj));
	}
}