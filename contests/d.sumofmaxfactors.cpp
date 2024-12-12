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

vector<int> maxFactor(1e5 + 7), pre(1e5 + 7, 0);
void sieve() 
{
    iota(all(maxFactor), 0);
    for (int i = 2; i <= 1e5 / 2 + 1;i++) 
    {
        if (maxFactor[i] == i) 
        {
            for (int j = 2 * i; j <= 1e5; j += i) 
                maxFactor[j] = i;
        }
    }

    forup(i, 2, 1e5 + 1)
        pre[i] = pre[i - 1] + maxFactor[i];
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    sieve();
    tests()
    {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << el;
    }
}