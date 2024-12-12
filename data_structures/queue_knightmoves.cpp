#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA08025
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

bool validpos(string pos)
{
    if (size(pos) > 2)
        return false;
    else
        return (pos[0] >= 'a' && pos[0] <= 'h') && 
            (pos[1] - '0' >= 1 && pos[1] - '0' <= 8);
}

string newpos(string pos, pair<int, int> move)
{
    return (char)(pos[0] + move.first) + to_string(pos[1] - '0' + move.second);
}

void BFS(string start, string end)
{
    vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    unordered_set<string> visited;
    queue<pair<string, int>> q;
    q.push({start, 0});
    visited.insert(start);
    int res = 1e3;

    while (!q.empty())
    {
        string curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (curr == end)
        {
            res = min(res, cnt); // res = cnt
            break;
        }
        for (auto x : moves)
        {
            string pot = newpos(curr, x);
            if (!visited.count(pot) && validpos(pot))
            {
                visited.insert(curr);
                q.push({pot, cnt + 1});
            }
        }
    }

    cout << ((res == 1e3) ? -1 : res) << el;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        string st, en;
        cin >> st >> en;
        BFS(st, en);
    }
}