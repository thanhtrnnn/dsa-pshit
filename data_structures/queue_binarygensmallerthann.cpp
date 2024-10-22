#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA08005
//FIFO
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE // CAREFUL!!
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

vector<string> res;
void init()
{
    queue<string> q;
    q.push("1");
    res.push_back("1");
    while (res.size() < 10000)
    {
        string top = q.front();
        q.pop();
        res.push_back(top + "0");
        res.push_back(top + "1");
        q.push(top + "0");
        q.push(top + "1");
    }
}

string decimal_toBinary(int n)
{
    string s = "";
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);
    // all correct
    // alternative 28tech
    init();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        // print(res, 0, n);
        // forup(i, 1, n + 1)
        //     cout << decimal_toBinary(i) << ' ';
        // mine
        queue<string> q;
        q.push("1");
        int cnt = 1;
        while (cnt < n)
        {
            q.push(q.front() + "0");
            cnt++;
            if (cnt == n)
                break;
            else {
                q.push(q.front() + "1");
                cnt++;
                cout << q.front() << " ";
                q.pop();
            }
        }

        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << el;
    }
}