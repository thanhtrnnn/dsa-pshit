#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSAKT012
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int n, k, ok = 0, sum = 0, ans = INT_MAX;
vector<int> a(100);

void backtrack(int sum, int cnt, int pos)
{
    if (sum == k)
    {
        ok = 1;
        ans = min(ans, cnt);
		return;
	}

    for (int j = pos; j <= n; j++)
    {
        if (sum + a[j] <= k)
            backtrack(sum + a[j], cnt + 1, j + 1); // j + 1 for distinct elems
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    cin >> n >> k;
    forloop(i, 1, n) cin >> a[i];
    backtrack(0, 0, 1);

    if (!ok)
        cout << "-1" << el;
    else
        cout << ans << el;
}