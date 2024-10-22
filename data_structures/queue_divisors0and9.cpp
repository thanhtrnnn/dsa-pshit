#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
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

vector<ll> genString;
ll ans[101];
void init()
{
    queue<string> q;
    q.push("9");
    genString.push_back(9);
    while (true)
    {
        string top = q.front();
        q.pop();
        if (top.length() == 9)
            break;
        genString.push_back(stoll(top + "0"));
        genString.push_back(stoll(top + "9"));
        q.push(top + "0");
        q.push(top + "9");
    }

    forup(i, 1, 101)
    {
        for (ll x : genString)
        {
            if (x % i == 0)
            {
                ans[i] = x;
                break;
            }
        }
        // cout << i << " " << ans[i] << el;
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);
    
    init();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        // cout << ans[n] << el;
        queue<string> q;
        q.push("9");
        
        while (stoll(q.front()) % n != 0)
        {
            q.push(q.front() + "0");
            q.push(q.front() + "9");
            q.pop();
        }
        cout << stoll(q.front()) << el;
    }
}