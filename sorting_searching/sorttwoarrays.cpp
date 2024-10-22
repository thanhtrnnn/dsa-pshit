#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06017
#define forloop(i, a, b) for (int i = (a); i < (b); i++)

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n, m; 
        cin >> n >> m;
        vector<int> a(n+m);
        forloop(i, 0, n+m) cin >> a[i];
        sort(a.begin(), a.end());
        for (int x : a) cout << x << " ";
        cout << endl;
    }
}