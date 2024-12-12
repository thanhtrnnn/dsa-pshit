#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02011
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int n, k, ans = 1000;
vector<int> a(100);

void backtrack(int sum, int cnt, int pos)
{
    if (cnt >= ans) // way faster
        return;
    if (sum == k)
    {   
        ans = min(ans, cnt);
		return;
	}
    else if (sum > k)
        return; 
    else {
        for (int j = pos; j <= n; j++)
            backtrack(sum + a[j], cnt + 1, j + 1); // j + 1 for distinct elems
    }
}

void backtrack2(int sum, int cnt, int pos)
{
    if (sum == k)
    {
        ans = min(ans, cnt);
		return;
	}
    for (int j = pos; j <= n; j++)
    {
        if (sum + a[j] <= k)
            backtrack(sum + a[j], cnt + 1, j + 1); // j + 1 for distinct elems
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> k;
        forloop(i, 1, n) cin >> a[i];
        // backtrack(0, 0, 1);
        backtrack2(0, 0, 1);
        cout << ((ans != 1000) ? to_string(ans) : "-1") << el;
        ans = 1000;
    }
}