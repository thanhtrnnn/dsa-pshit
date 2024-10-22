#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02032
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int n, k, sum = 0, ok = 0;
vector<int> a(1000), X(1000);
vector<vector<int>> res;

// j de bai lua day dang ra phai sort
void backtrack(int sum, int cnt, int pos)
{
    if (sum == k)
    {
        ok = 1;
        // sort(X.begin() + 1, X.begin() + cnt);
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
            backtrack(sum + a[j], cnt + 1, j); // j + 1 for distinct elems
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--)
    {
        cin >> n >> k;
        forloop(i, 1, n) cin >> a[i];
        backtrack(0, 1, 1);

        if (!ok)
        {
            cout << "-1" << el;
            continue; // yissssssssss
        }

        cout << res.size() << ' ';
        for (auto x : res)
        {
            cout << '{';
            forloop(i, 0, (int)x.size() - 2)
                cout << x[i] << ' ';
            cout << x[(int)x.size() - 1] << "} ";
        }
        ok = 0;
        res.clear();
        cout << el;
    }
}