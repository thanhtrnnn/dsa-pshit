#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1320
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int n, k;
int X[100];
int sum = 0, ok = 0;
int a[1000];

void Try1(int i, int pos)
{
    for (int j = pos; j <= n; j++)
    {
        X[i] = a[j];
        sum += a[j];
        if (sum == k)
        {
            ok = 1;
            sort(X + 1, X + i + 1);
            cout << "[";
            for (int p = 1; p <= i; p++)
            {
                (p != i) ? cout << X[p] << " "
                            : cout << X[p];
            }
            cout << "]";
        }

        // recursion only if this:
        else if (sum + a[j] <= k)
            Try1(i + 1, j);
        sum -= a[j];
    }
}

void Try2(int sum, int cnt, int pos)
{
    if (sum == k)
    {
        ok = 1;
        sort(X + 1, X + cnt); // optional
        cout << "[";
		for (int i = 1; i < cnt; i++)
        {
            (i != cnt - 1) ? cout << X[i] << " "
                        : cout << X[i];
        }
        cout << "]";
		return;
	}

    for (int j = pos; j <= n; j++)
    {
        if (sum + a[j] <= k)
        {
            X[cnt] = a[j];
            Try2(sum + a[j], cnt + 1, j); // j + 1 for distinct elems
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> k;
        forloop(i, 1, n) cin >> a[i];
        // Try1(1, 1);
        Try2(0, 1, 1);
        if (!ok)
            cout << "-1";
        cout << el;
    }
}