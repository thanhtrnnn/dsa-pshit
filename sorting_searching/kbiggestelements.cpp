#include <bits/stdc++.h>
using namespace std;

//DSA06012
using ll = long long;

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
        int n, k; 
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        sort (a.begin(), a.end(), greater<int>());
        for (int i = 0; i < k; i++) cout << a[i] << " ";
        cout << endl;
    }
}