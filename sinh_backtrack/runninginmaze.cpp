#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02012
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int n, m, a[105][105], res = 0;

void backtrack(int row, int col, string s)
{   
    if (row == n && col == m)
        res++;
    // move down behavior
    if (row + 1 <= n)
        backtrack(row + 1, col, s + "D");
    
    // move right behavior
    if (col + 1 <= m)
        backtrack(row, col + 1, s + "R");
    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        cin >> n >> m;
        forloop(i, 1, n)
            forloop(j, 1, m)
                cin >> a[i][j];
        backtrack(1, 1, "");
        cout << res << el;
        res = 0;
    }
}