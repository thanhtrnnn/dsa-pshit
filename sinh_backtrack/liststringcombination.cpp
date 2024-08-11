#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1316
#define forloop(i, a, b) for (int i = (a); i < (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int n;
string s, current;
vector<string> all;
void genString(int pos)
{
    all.push_back(current);
    forloop(i, pos, n)
    {
        current.push_back(s[i]);
        genString(i + 1);
        current.pop_back();
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        cin >> n >> s;
        current = "";
        genString(0);
        sort(all.begin(), all.end());
        for (string &subset : all)
            if (subset != "") cout << subset << " ";
        cout << el;
        all.clear();
    }
}