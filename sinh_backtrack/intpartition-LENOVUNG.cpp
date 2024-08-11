#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a) forloop(i, 0, n) cout << a[i] << " "

bool ok;
void next(vector<int> &a, int &cnt) // example: 8, 4 2 1 1
{
    int i = cnt; // i = 4
    while (a[i] == 1 && i != 0) --i; // ignore the 1s

    if (i == 0) ok = false; // last profile
    else { // i = 2
        a[i]--; // a[2] = 1
        int remain = cnt - i + 1; // 4 - 2 + 1 = 3 left
        cnt = i; // 4 and 1 -> cnt = i = 2

        int tmp = remain / a[i]; // tmp = 3 / 1 = 3
        int r = remain % a[i]; // r = 1
        if (tmp) // runs only if tmp != 0
        {
            forloop(j, 1, tmp) 
                a[++cnt] = a[i]; // write tmp times the a[i]
        }
        if (r)
            a[++cnt] = r; // r left
    }
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
        int n; cin >> n;
        vector<int> a(n+1, 0);

        ok = true;
        a[1] = n; // init
        int cnt = 1; // keep track of the number of elements
        while (ok)
        {
            cout << "(";
            forloop (i, 1, cnt) 
            {
                (i != cnt) ? cout << a[i] << " "
                        : cout << a[i];
            }
            cout << ") ";
            next(a, cnt);
        }
        cout << endl;
    }
}