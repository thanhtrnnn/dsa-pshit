#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06025
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

void insertionsort(vector<int> &a, int n)
{
    forup(i, 0, n)
    {
        if (i != 0)
        {
            int target = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > target)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = target;
        }
        // print step
        int c = i;
        cout << "Buoc " << c << ": ";
        print(a, 0, c + 1);
        cout << el;
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    forup(i, 0, n) cin >> a[i];
    insertionsort(a, n);
}