#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02039
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

int n;
vector<int> nums(20);
vector<string> res;

void backtrack(int pos, int sum, int pre, string s)
{
    fordown(i, pre, 1) // previous > after
    {
        if (sum == n)
        {
            s.pop_back(); // remove blank space
            res.push_back('(' + s + ')');
            return;
        }

        else if (sum < n)
            backtrack(pos + 1, sum + i, i, s + to_string(i) + ' ');
        else return;
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        cin >> n;
        backtrack(1, 0, n, "");

        cout << res.size() << el;
        for (string prof : res)
            cout << prof << ' ';
        res.clear();
        cout << el;
    }
}