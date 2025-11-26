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

const int N = 310;
// This code is for calculating the minimum number of matrix multiplications needed to multiply a chain of matrices.
// L[i][j] = minimum number of multiplications needed to multiply matrices from i to j.
int d[N], L[N][N], n;

int calc(int i, int j)
{
    if (L[i][j] == -1)
    {
        if (i == j)
            L[i][j] = 0;
        else
        {
            L[i][j] = calc(i + 1, j) + d[i - 1] * d[i] * d[j];
            for (int k = i; k < j; k++)
                L[i][j] = min(L[i][j], calc(i, k) + calc(k + 1, j) + d[i - 1] * d[k] * d[j]);
        }
    }
    return L[i][j];
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> d[i];
    for (int dis = 1; dis < n; dis++)
    {
        for (int i = 1; i + dis <= n; i++)
        {
            int j = i + dis;
            L[i][j] = L[i + 1][j] + d[i - 1] * d[i] * d[j];
            for (int k = i; k < j; k++)
                L[i][j] = min(L[i][j], L[i][k] + L[k + 1][j] + d[i - 1] * d[k] * d[j]);
        }
    }
    cout << L[1][n];
}