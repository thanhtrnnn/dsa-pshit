#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02013
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

bool isPrime(int n) 
{
	if (n < 2)
        return 0;
	else
		for (int i = 2; i <= sqrt(n); i++)
			if (n % i == 0)
                return 0;
	return 1;
}

int n, p, s;
vector<int> x, a;
vector<vector<int>> res;
void backtrack(int sum, int cnt, int pos)
{
    for (int i = pos + 1; i < (int)a.size(); i++)
    {
        if (sum + a[i] == s && cnt == n - 1)
        {
            x.push_back(a[i]);
            res.push_back(x);
            x.pop_back();
        }
        else if (cnt < n - 1 && sum + a[i] < s)
        {
            x.push_back(a[i]);
            backtrack(sum + a[i], cnt + 1, i);
            x.pop_back();
        }
    }

}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);
    forup(i, 2, 201)
            if (isPrime(i))
                a.push_back(i);
    tests()
    {
        res.clear();
        cin >> n >> p >> s;
        int l = upper_bound(a.begin(), a.end(), p) - a.begin();
        backtrack(0, 0, l - 1);

        cout << res.size() << el;
        for (auto x : res)
        {
            for (auto c : x)
                cout << c << ' ';
            cout << el;
        }
    }
}