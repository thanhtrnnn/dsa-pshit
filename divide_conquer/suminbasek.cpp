#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA04007
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

string baseKsum(string a, string b, int k)
{
    while (size(a) > size(b))
        b.insert(0, "0");
    while (size(a) < size(b))
        a.insert(0, "0");
    
    int carri = 0;
    fordown(i, size(a) - 1, 0)
    {
        int d = a[i] - '0' + b[i] - '0' + carri;
        carri = d / k;
        a[i] = '0' + d % k;
    }
    if (carri)
        a.insert(0, to_string(carri));
    if (a[0] == '0') 
        a.erase(a.begin());

    return a;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int k; cin >> k;
        string a, b;
        cin >> a >> b;
        cout << baseKsum(a, b, k) << el;
    }
}