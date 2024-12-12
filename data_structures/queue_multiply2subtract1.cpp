#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA08009
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

int ramp(int s, int t)
{
    queue<pair<int, int>> q; // num generated and steps
    set<int> uniq;
    q.push({s, 0});
    uniq.insert(s);
    while (!q.empty())
    {
        int num = q.front().first;
        int step = q.front().second;
        q.pop();

        // out conditions
        if (num == t)
            return step;
        if (num * 2 == t || num - 1 == t)
            return step + 1;
        
        if (!uniq.count(num * 2) && num < t)
        {
            q.push({num * 2, step + 1});
            uniq.insert(num * 2);
        }
        if (!uniq.count(num - 1) && num > 1)
        {
            q.push({num - 1, step + 1});
            uniq.insert(num - 1);
        }
    }
    return 0;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int s, t; 
        cin >> s >> t;
        cout << ramp(s, t) << el;
    }
}