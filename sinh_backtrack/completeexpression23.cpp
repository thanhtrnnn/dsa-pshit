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
#define size(a)             (int)a.size()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

int a[5], f; 
void backtrack(int i, int sum)
{ 
    if (f) 
        return; 
    if (i > 4)
    { 
        if (sum == 23) 
            f = 1; 
        return; 
    } 
    backtrack(i + 1, sum + a[i]); 
    backtrack(i + 1, sum - a[i]); 
    backtrack(i + 1, sum * a[i]); 
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        for (int &x : a) 
            cin >> x; 
        sort(a, a + 5); 
        f = 0; 
        do { 
            backtrack(1, a[0]); 
        } 
        while (next_permutation(a, a + 5) && !f); 
        cout << (f ? "YES\n" : "NO\n");        
    }
}