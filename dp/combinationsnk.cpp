#include <iostream>
using namespace std;
using ll = long long;

//DSA05012
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define el                  "\n"
const int MOD=1e9+7;

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

int n, k; 
ll a[1005][1005]; 
void sang()
{ 
    a[1][0] = 1; 
    a[1][1] = 1; 
    for (int i = 2; i <= n; i++) 
    { 
        for (int j = 0; j <= i; j++)
        { 
            if (j == 0 || j == i) 
                a[i][j] = 1;
            // nCk = n-1Ck + n-1Ck-1
            else a[i][j] = (a[i-1][j-1] + a[i-1][j]) % MOD; 
        } 
    } 
}

int binomialCoeff()
{
    ll C[k + 1] = {};
    C[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % MOD;
    }
    return C[k] % MOD;
}

ll modpow(ll a, int b, int m)
{
    if (b == 0) 
        return 1;
    ll res = modpow(a, b/2, m);
    res = (res * res) % m;
    if (b % 2) 
        res = (res * a) % m;
    return res;
}

ll mod (ll n, int m)
{
    return modpow(n, m-2, m);
}

ll solve (int n, int r, int p)
{
    if (n < r) return 0;
    if (r == 0) return 1;
    ll fac[1005];
    fac[0] = 1;
    forup(i, 1, n + 1)    
        fac[i] = (fac[i-1] * i) % p;

    // fac[n] / (fac[r] * fac[n - r])
    return (fac[n] * mod(fac[r], p) % p * mod(fac[n-r], p) % p) % p;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        // int n, k, p = 1e9+7;
        // cin >> n >> k;
        // cout << solve(n, k, p) << endl;
        cin >> n >> k;
        // cout << binomialCoeff() << el;
        sang(); 
        cout << a[n][k] << el;
    }
}