#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02002
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

vector<vector<int>> res;
void recursion(vector<int> a, int cnt)
{
    vector<int> tmp;
    if (cnt == 0)
        return;

    for (int j = 1; j < cnt; j++)
    {
        tmp.push_back(a[j]);
        a[j] += a[j + 1];            
    }
    tmp.push_back(a[cnt]);
    
    res.push_back(tmp);
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
        for (int x = res.size() - 1; x >= 0; x--)
        {
            cout << "[";
            forloop(i, 0, (int)res[x].size() - 1)
            {
                (i != res[x].size() - 1) ? cout << res[x][i] << " "
                                    : cout << res[x][i];
            }
            cout << "] ";
        }
        res.clear();
        cout << el;
    }
}