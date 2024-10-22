#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06016
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
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        ll max = INT_MIN, min = INT_MAX;
        forloop(i, 0, n)
        {
            cin >> a[i];
            max = (max < a[i]) ? a[i] : max;
        }
        forloop(i, 0, m)
        {
            cin >> b[i];
            min = (min > b[i]) ? b[i] : min;
        }
        cout << max * min << endl;
    }
}