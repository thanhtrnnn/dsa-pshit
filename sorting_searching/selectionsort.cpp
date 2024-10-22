#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06022
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

void selectionsort(vector<int> &a, int n)
{
    forup(i, 0, n - 1)
    {
        int min = INT_MAX, min_idx;
        forup(j, i, n)
        {
            if (a[j] < min)
            {
                min = a[j];
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
        // print step
        cout << "Buoc " << i + 1 << ": ";
        print(a, 0, n);
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
    selectionsort(a, n);
}