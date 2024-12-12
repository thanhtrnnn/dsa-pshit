#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02030
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

void backtrack(int pos, int k, int fin, string s)
{
    if (pos == k)
    {
        cout << s << el;
        return;
    }
    for (char c = 'A'; c <= fin; c++)
    {
        if (c >= s.back())
            backtrack(pos + 1, k, fin, s + c);
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    char fin;
    int k; 
    cin >> fin >> k;
    backtrack(0, k, fin, "");
}