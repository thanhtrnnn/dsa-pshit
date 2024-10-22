#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02017
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

bool column[10] = {}, 
    upDiag[20] = {}, 
    downDiag[20] = {};
int solution[10] = {}, maxscore = -1;
int n, scoreboard[8][8];

void backtrack(int pos, int curscore)
{
    if (pos == 9)
    {
        maxscore = max(maxscore, curscore);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!column[i] && !downDiag[pos - i + n] && !upDiag[pos + i - 1])
        {
            solution[pos] = i;
            column[i] = downDiag[pos - i + n] = upDiag[pos + i - 1] = true;
            backtrack(pos + 1, curscore + scoreboard[pos - 1][i - 1]);
            column[i] = downDiag[pos - i + n] = upDiag[pos + i - 1] = false;
        }
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        maxscore = 0;
        n = 8;
        forup(i, 0, n)
            forup(j, 0, n)
                cin >> scoreboard[i][j];
        backtrack(1, 0);
        cout << maxscore << el;
    }
}