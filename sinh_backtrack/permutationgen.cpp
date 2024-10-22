#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA01005
int n, a[100];
bool trace[100] = {};

void print()
{
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << endl;
}

void backtrack(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!trace[j])
        {
            // check j condition: mark j as used
            trace[j] = true;
            a[i] = j;
            if (i == n) print();
            // recursion
            else backtrack(i + 1);
            // go back & mark j as never used
            trace[j] = false;
        }
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
    while (t--)
    {   
        cin >> n;
        backtrack(1);
        cout << endl;
    }
}