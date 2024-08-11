#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1310
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

void nextCombination(vector<int> &a, int n, int k)
{
    int i = k;
    while (a[i] == n - k + i && i != 0) --i;

    if (i != 0) a[i]++;
    forloop(j, i+1, k) a[j] = a[j-1] + 1;
    print(a, 1, k);
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
        int n, k;
        cin >> n >> k;
        vector<int> a(k+1);
        forloop(i, 1, k) cin >> a[i];
        nextCombination(a, n, k);
    }
}