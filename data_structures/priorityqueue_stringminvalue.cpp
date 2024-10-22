#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA03017, DSA08004
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forloop(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
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

    int t; cin >> t;
    while(t--)
    {
        int k;
        string s;
        cin >> k >> s;
        map<char, int> mp;
        for (char x : s) 
            mp[x]++;

        priority_queue<int> pq;
        ll res = 0;
        for (auto x : mp)
        {
            pq.push(x.second);
            // res += 1ll * x.second * x.second;
        }

        // in denial
        // while (k > 0 && !pq.empty())
        // {
        //     if (pq.top() <= k)
        //     {
        //         res -= 1ll * pq.top() * pq.top();
        //         k -= pq.top();
        //         pq.pop();
        //     }
        //     else {
        //         res -= 1ll * (pq.top() * pq.top() 
        //             - 1ll * (pq.top() - k) * (pq.top() - k));
        //         k = 0;
        //     }
        // }

        // alternatives 28tech
        while (k > 0)
        {
            // biggest freq in pq
            int top = pq.top();
            pq.pop();
            --top;
            --k;
            pq.push(max(0, top));
        }
        while (!pq.empty())
        {
            res += 1ll * pq.top() * pq.top();
            pq.pop();
        }

        cout << res << el;
    }
}