#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1311
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

void nextPermutation(vector<int> &a, int n)
{
    int i = n - 1;
    while (i >= 1 && a[i] > a[i+1]) --i;

    if (i != 0)
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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n+1);
        forloop(i, 1, n) cin >> a[i];
        nextPermutation(a, n);
    }
}