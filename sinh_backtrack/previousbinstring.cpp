#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1312
#define forloop(i, a, b) for (int i = (a); i < (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

string prevBinaryString(string s)
{
    int n = s.length();
    int i = n-1;
    while (s[i] == '0' && i != -1)
    {
        s[i] = '1';
        --i;
    }
    if (i != -1) s[i] = '0';
    return s;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        cout << prevBinaryString(s) << el;
    }
}