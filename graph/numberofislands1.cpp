#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA09011
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "; cout << el
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define size(a)             (int)a.size()
#define el                  "\n"
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}; 
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

int n, m;
void DFS(vector<vector<int>> &a, int i, int j)
{
    a[i][j] = 0; 
    forup(k, 0, 8)
    {
        int i1 = i + dx[k], j1 = j + dy[k]; 
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1])
            DFS(a, i1, j1);
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        forup(i, 0, n) 
            forup(j, 0, m)
                cin >> a[i][j];

        int islands = 0;
        forup(i, 0, n) 
        {
            forup(j, 0, m)  
            {
                if (a[i][j])
                {
                    ++islands;
                    DFS(a, i, j);
                }
            }      
        }

        cout << islands << el;
    }
}