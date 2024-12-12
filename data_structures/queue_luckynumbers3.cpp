#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA08019
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define size(a)             (int)a.size()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

vector<string> res;
// void init()
// {
//     queue<string> q;
//     q.push("6");
//     q.push("8");
//     res.push_back("6");
//     res.push_back("8");
//     while (true)
//     {
//         string top = q.front();
//         q.pop();
//         if (top.length() == 15)
//             break;
//         res.push_back(top + "6");
//         res.push_back(top + "8");
//         q.push(top + "6");
//         q.push(top + "8");
//     }
// }

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    // init();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        // vector<string> res;
        // for (string x : res)
        // {
        //     if (x.length() > n) break;
        //     res.push_back(x);
        // }
        // reverse(res.begin(), res.end());
        // for (string kmm : res)
        //     cout << kmm << " ";
        // cout << el;
        res.clear();
        queue<string> q;
        q.push("6");
        q.push("8");
        res.push_back("6");
        res.push_back("8");
        int curr = 0;
        while (curr < n)
        {
            string top = q.front();
            q.pop();
            res.push_back(top + "6");
            res.push_back(top + "8");
            q.push(top + "6");
            q.push(top + "8");
            curr = size(q.front());
        }
        
        cout << size(res) << el;
        for (int i = size(res) - 1; i >= 0; i--)
            cout << res[i] << ' ';
        cout << el;
    }
}