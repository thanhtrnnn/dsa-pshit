#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02004
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int a[30][30], n;
bool ok, check[30][30];
char res[1000];
vector<string> S;

void Try2(int x, int y, string s) {
	if (x > n || y > n || x < 1 || y < 1) return;
	if (check[x][y] || a[x][y] == 0) return;
	if (x == n && y == n) {
		cout << s << " ";
        ok = true;
		return;
	}
	check[x][y] = true;
	Try2(x + 1, y, s + "D");
	Try2(x, y - 1, s + "L");
	Try2(x, y + 1, s + "R");
    Try2(x - 1, y, s + "U");
	check[x][y] = false;
}

// wrong func, printing profiles like "DURD", "RLDR"
// -> not allowed to go back 
void Try(int i, int j, string s){
    //if (a[i][j] == 0) return;
    if (i == n && j == n){
        ok = 1;
        cout << s << " ";
        return;
    }
    if (i + 1 <= n && a[i + 1][j] == 1){
        a[i + 1][j] = 0;
        Try(i + 1, j, s + "D");
        a[i + 1][j] = 1; 
    }
    if (j - 1 >= 1 && a[i][j - 1] == 1){
        a[i][j - 1] = 0;
        Try(i, j - 1, s + "L");
        a[i][j - 1] = 1;
    }
    if (j + 1 <= n && a[i][j + 1] == 1){
        a[i][j + 1] = 0;
        Try(i , j + 1, s + "R");
        a[i][j + 1] = 1;
    }
    if (i - 1 >= 1 && a[i - 1][j] == 1){
        a[i - 1][j] = 0;
        Try(i - 1, j, s + "U");
        a[i - 1][j] = 1;
    }
}

void backtrack(int row, int col, int k)
{
    if (row == n && col == n)
    {
        forloop(i, 0, k - 1)
            cout << res[i];
        cout << " ";
        ok = true;
        return;
    }
    if (row + 1 <= n && a[row + 1][col] == 1)
    {
        res[k] = 'D';
        a[row + 1][col] = 0;
        backtrack(row + 1, col, k + 1);
        a[row + 1][col] = 1;
    }
    if (col - 1 >= 1 && a[row][col - 1] == 1)
    {
        res[k] = 'L';
        a[row][col - 1] = 0;
        backtrack(row, col - 1, k + 1);
        a[row][col - 1] = 1;
    }
    if (col + 1 <= n && a[row][col + 1] == 1)
    {
        res[k] = 'R';
        a[row][col + 1] = 0;
        backtrack(row, col + 1, k + 1);
        a[row][col + 1] = 1;
    }
    if (row - 1 >= 1 && a[row - 1][col] == 1)
    {
        res[k] = 'U';
        a[row - 1][col] = 0;
        backtrack(row - 1, col, k + 1);
        a[row - 1][col] = 1;
    }
    // alphabetical order: DLRU
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
        cin >> n;
        forloop(i, 1, n) 
            forloop(j, 1, n)
                cin >> a[i][j];

        ok = false;
        if (a[1][1] && a[n][n])
        {
            // solution 1
            // Try2(1, 1, "");
            // solution 2
            a[1][1] = 0; // never go back to the start - key of the problem
            backtrack(1, 1, 0);
            // Try(1, 1, "");
        }
        if (!ok)
            cout << "-1";
        cout << el;
    }
}