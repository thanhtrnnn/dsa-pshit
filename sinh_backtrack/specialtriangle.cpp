#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02001
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

void recursion(vector<int> a, int cnt)
{
    // base condition
    if (cnt == 0)
        return;
    
    // valid profile
    cout << "[";
    for (int j = 1; j < cnt; j++)
    {
        cout << a[j] << " ";
        a[j] += a[j + 1];            
    }
    cout << a[cnt] << "]" << el;

    // driver
    recursion(a, cnt - 1);
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
        recursion(a, n);
    }
}