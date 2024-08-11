#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

void backtrack(vector<int> a, int n, int cnt)
{
    if (cnt == 0)
        return;
    cout << "[";
    for (int j = 1; j < cnt; j++)
    {
        cout << a[j] << " ";
        a[j] += a[j + 1];            
    }
    cout << a[cnt] << "]" << el;
    backtrack(a, n, cnt - 1);
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
        int n; cin >> n;
        vector<int> a(n + 1);
        forloop(i, 1, n) cin >> a[i];
        backtrack(a, n, n);
    }
}