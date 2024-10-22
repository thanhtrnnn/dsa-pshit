#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//CTDL_002
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int n, k, total = 0;
int sum = 0, ok = 0;
vector<int> a(1000), X(1000);
vector<vector<int>> res;

void Try1(int i, int pos) // list increasingly
{
    for (int j = pos; j <= n; j++)
    {
        X[i] = a[j];
        sum += a[j];
        if (sum == k)
        {
            ok = 1;
            sort(X.begin() + 1, X.begin() + i + 1);
            for (int p = 1; p <= i; p++)
            {
                (p != i) ? cout << X[p] << " "
                            : cout << X[p];
            }
            cout << el;
        }

        // recursion only if this:
        else if (sum + a[j] <= k)
            Try1(i + 1, j + 1);
        sum -= a[j];
    }
}

void Try2(int sum, int cnt, int pos) // list decreasingly
{
    if (sum == k)
    {
        ok = 1;
        total++;
        // sort(X + 1, X + cnt); // optional
        vector<int> tmp;
		forloop(i, 1, cnt - 1)
            tmp.push_back(X[i]);
        res.push_back(tmp);
		return;
	}

    for (int j = pos; j <= n; j++)
    {
        if (sum + a[j] <= k)
        {
            X[cnt] = a[j];
            Try2(sum + a[j], cnt + 1, j + 1); // j + 1 for distinct elems
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    cin >> n >> k;
    forloop(i, 1, n) cin >> a[i];
    // Try1(1, 1);
    Try2(0, 1, 1);

    sort(res.begin(), res.end(), greater<vector<int>>());
    for (auto x : res)
    {
        for (auto y : x)
            cout << y << " ";
        cout << el;
    }
    
    if (!ok)
        cout << "-1";
    else
        cout << total;
    cout << el;
}