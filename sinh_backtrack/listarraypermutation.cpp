#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA01027
#define forloop(i, a, b) for (int i = (a); i < (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int n;
vector<int> s;
vector<vector<int>> allstr;

void backtrack(int pos)
{
    if (pos == n - 1) 
        allstr.push_back(s);
    for (int i = pos; i < n; i++)
    {
        swap(s[i], s[pos]);
        backtrack(pos + 1);
        swap(s[i], s[pos]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    forloop(i, 0, n)
    {
        int elem; cin >> elem;
        s.push_back(elem);
    }
    backtrack(0);
    sort(allstr.begin(), allstr.end());
    for (auto x : allstr)
    {
        for (int z : x)
            cout << z << " ";
        cout << el;
    }
    allstr.clear();
}