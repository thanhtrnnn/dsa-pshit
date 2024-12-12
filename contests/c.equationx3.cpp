#include <iostream>
#include <cmath>
#include <iomanip>
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

double solve(int A, int B, int C) 
{
    double left = -1000, right = 1000;
    double mid;
    while (right - left > 1e-8) 
    {  
        mid = (left + right) / 2;
        if (A * mid * mid * mid + B * mid > C) 
            right = mid; 
        else 
            left = mid;
    }
    return mid; 
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int a, c, d;
        cin >> a >> c >> d;
        cout << fixed << setprecision(4) << solve(a, c, d) << el;
    }
}