#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02033
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << ""
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

bool isAdjacentArray(vector<int> a)
{
    forup(i, 0, (int)a.size() - 1)
    {
        if (abs(a[i] - a[i + 1]) == 1)
            return false;
    }
    return true;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        vector<int> elem;
        forup(i, 1, n + 1)
            elem.push_back(i);
        do {
            if (isAdjacentArray(elem))
            {
                print(elem, 0, n);
                cout << el;
            }
        }
        while (next_permutation(all(elem)));
    }
}