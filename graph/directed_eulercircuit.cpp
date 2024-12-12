#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA10005
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

int main()
{
    fileio();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	tests()
    {
		int vertices, edges;
        cin >> vertices >> edges;
        vector<int> in[vertices + 1], out[vertices + 1];
        forup(i, 0, edges)
        {
            int u, v;
            cin >> u >> v;
            // u -> v
            out[u].push_back(v);
            in[v].push_back(u);
        }
		
        bool isEuler = true;
        forup(i, 1, vertices + 1)
        {
            if (size(in[i]) != size(out[i])) // all size in == size out
            {
                isEuler = false;
                break;
            }
        }

        cout << (isEuler ? 1 : 0) << el;
	}
}