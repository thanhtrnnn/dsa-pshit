#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA01001
#define forloop(i, a, b) for (int i = (a); i < (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

string nextBinaryString(string s)
{
    int n = s.length();
    int i = n - 1;
    while (s[i] == '1' && i != -1) 
    {
        s[i] = '0';
        --i;
    }
    if (i != -1) s[i] = '1';
    return s;
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
        string s; cin >> s;
        cout << nextBinaryString(s) << el;
    }
}