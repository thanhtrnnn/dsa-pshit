#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA09020
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
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    cin.ignore();
    int adj[n + 1][n + 1] = {};
    forup(i, 1, n + 1)
    {
        string s, buf; 
        getline(cin, s);
		stringstream ss(s);
		while (ss >> buf)
			adj[i][stoi(buf)] = adj[stoi(buf)][i] = 1;
    }
    
    forup(i, 1, n + 1)
    {
        print(adj[i], 1, n + 1);
    }
}