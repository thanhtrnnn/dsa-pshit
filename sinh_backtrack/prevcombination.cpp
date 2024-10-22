#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA01018
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

void printt(vector<int> a, int n)
{
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << " ";
}

void prevCombination(vector<int> &a, int n, int k)
{
    int i = k;
    while (i != 0 && a[i] == a[i - 1] + 1) --i;
    
    if (i != 0) a[i]--;
    forloop(j, i+1, k) a[j] = n - k + j;
    print(a, 1, k);
}

void backtrack(vector<int> &a, int n, int k, int i)
{
    if (i == k)
    {
        printt(a, k);
        return;
    }
    else {
        for (int j = a[i - 1] + 1; j <= n - k + i; j++)
        {
            a[j]--;
            backtrack(a, n, k, i + 1);
            a[j]++;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(k+1);
        forloop(i, 1, k) cin >> a[i];
        prevCombination(a, n, k);
        // backtrack(a, n, k, 1);
        cout << el;
    }
}