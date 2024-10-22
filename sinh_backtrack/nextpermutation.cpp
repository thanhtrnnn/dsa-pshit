#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA01003
#define forloop(i, a, b) for (int k = (a); k <= (b); k++)
#define print(a, x, y) forloop(k, x, y) cout << a[k] << " "
#define el "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

void nextPermutation(vector<int> &a, int n)
{
    int i = n - 1;
    while (i >= 1 && a[i] > a[i+1]) --i;

    if (i == 0)
        reverse(a.begin() + 1, a.end());
    else
    {
        int j = n;
        while (a[i] > a[j]) --j;
        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.end());
    }
    print(a, 1, n);
    cout << el;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n+1);
        forloop(k, 1, n) cin >> a[k];
        nextPermutation(a, n);
    }
}