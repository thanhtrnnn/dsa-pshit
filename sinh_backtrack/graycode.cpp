#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define el "\n"

int n, a[100] = {};
bool ok;

void print()
{
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << " ";
}

bool check()
{
    if (a[1] == 0) return false;
    forloop(i, 2, n)
        if (a[i] != 0) return false;
    return true;
}

void solve()
{
    if (check()) ok = false;
    forloop(i, 1, n-1)
    {
        a[i] = (a[i] == a[i + 1]) ? 0 : 1;
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
        cin >> n;
        ok = true;
        print();
        a[n] = 1;
        while (ok)
        {
            print();
            solve();
        }
        cout << el;
    }
}