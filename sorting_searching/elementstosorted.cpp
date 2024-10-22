#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06018
#define forloop(i, a, b) for (int i = (a); i < (b); i++)

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        forloop(i, 0, n) cin >> a[i];
        sort(a.begin(), a.end());

        int res = 0;
        forloop(i, 1, n)
            if (a[i] != a[i-1]) 
                res += (a[i] - a[i-1] - 1);
        cout << res << endl;
    }
}