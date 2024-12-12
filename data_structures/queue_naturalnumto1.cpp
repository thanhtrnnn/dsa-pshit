#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "; cout << el
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


int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        queue<pair<int, int>> q;
        unordered_set<int> uniq;
        q.push({n, 0});
        uniq.insert(n);

        while (!q.empty())
        {
            int curr = q.front().first;
            int step = q.front().second;
            q.pop();
            if (curr == 1)
            {
                cout << step << el;
                break;
            }
            
            for (int i = 2; i * i <= curr; i++) 
            {
				if (curr % i == 0 && !uniq.count(curr / i)) 
                {
					q.push({curr / i, step + 1});
					uniq.insert(curr / i);
				}
			}
            if (!uniq.count(curr - 1) && curr > 1)
            {
                q.push({curr - 1, step + 1});
                uniq.insert(curr - 1);
            }
            
        }
    }
}