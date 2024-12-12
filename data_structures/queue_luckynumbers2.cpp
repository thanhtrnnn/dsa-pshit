#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA08018
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

vector<string> genString;
void gen(int n)
{
    queue<string> q;
    q.push("6");
    q.push("8");
    int curr = 0;
    while (curr <= n)
    {
        string top = q.front();
        q.pop();
        genString.push_back(top);
        q.push(top + "6");
        q.push(top + "8");
        curr = size(q.front());
    }
}

void gen2(int n) // declare vec out of main -> less memory
{
    queue<string> q;
    q.push("6");
    q.push("8");
    genString.push_back("6");
    genString.push_back("8");
    int curr = 0;
    while (curr < n)
    {
        string top = q.front();
        q.pop();
        genString.push_back(top + "6");
        genString.push_back(top + "8");
        q.push(top + "6");
        q.push(top + "8");
        curr = size(q.front());
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        gen(n);

        cout << size(genString) << el;
        for (string x : genString)
            cout << x << ' ';
        cout << el;
        genString.clear();
    }
}