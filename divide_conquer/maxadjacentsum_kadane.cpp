#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA04010
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

int kadane(vector<int> &a, int n)
{
    ll max_so_far = INT_MIN, 
        max_ending_here = 0;

    forup(i, 0, n)
    {
        // max_ending_here = max_ending_here + a[i];
        // if (max_so_far < max_ending_here)
        //     max_so_far = max_ending_here;
            
        // if (max_ending_here < 0)
        //     max_ending_here = 0;
        max_ending_here = max(max_ending_here + a[i], (ll)a[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        vector<int> a(n);
        forup(i, 0, n) cin >> a[i];
        cout << kadane(a, n) << el;
    }
}