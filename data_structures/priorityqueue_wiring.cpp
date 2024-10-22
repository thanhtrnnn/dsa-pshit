#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA03010
#define forloop(i, a, b) for (int i = (a); i < (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

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
        int n; cin >> n;
        vector<int> a(n);
        forloop(i, 0, n) cin >> a[i];
        
        // initialize a min heap: parent node < leaf node
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : a)
            pq.push(x);
        
        // solve
        ll res = 0;
        // quit when pq has the final wire
        while (pq.size() > 1)
        {
            // two shortest wires forming a new wire
            // then pop them
            int newWire = pq.top();
            pq.pop();
            newWire += pq.top();
            pq.pop();

            // push that new wire to pq, then update res
            pq.push(newWire);
            res += newWire;
        }
        cout << res << el;
    }
}