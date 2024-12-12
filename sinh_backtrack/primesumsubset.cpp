#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02037
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define size(a)             (int)a.size()
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
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false;

    return n > 1;
}

int n;
vector<vector<int>> res;
vector<int> a, prof;
void backtrack(int pos, int sum)
{
    forup(i, pos, n)
    {
        prof.push_back(a[i]);
        if (isPrime(sum + a[i]))
            res.push_back(prof);
        backtrack(i + 1, sum + a[i]);
        prof.pop_back();
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        cin >> n;
        forup(i, 0, n)
        {
            int x; cin >> x;
            a.push_back(x);
        }
        sort(all(a), greater<int>());
        backtrack(0, 0);
        sort(all(res));
        for (auto x : res)
        {
            for (auto c : x)
                cout << c << ' ';
            cout << el;
        }
        a.clear();
        res.clear();
    }
}