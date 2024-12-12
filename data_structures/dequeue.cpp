#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA08003
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
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

    int n; cin >> n;
    deque<int> dq;
    string s;
    while (cin >> s)
    {
        if (s == "PUSHBACK")
        {
            int x; cin >> x;
            dq.push_back(x);
        }
        else if (s == "PUSHFRONT")
        {
            int x; cin >> x;
            dq.push_front(x);
        }
        else if (s == "PRINTFRONT")
            (dq.empty()) ? cout << "NONE" << el : cout << dq.front() << el;
        else if (s == "PRINTBACK")
            (dq.empty()) ? cout << "NONE" << el : cout << dq.back() << el;
        else if (s == "POPFRONT" && !dq.empty())
            dq.pop_front();
        else if (s == "POPBACK" && !dq.empty())
            dq.pop_back();
    }
}