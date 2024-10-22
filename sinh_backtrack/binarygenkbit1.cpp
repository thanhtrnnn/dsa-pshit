#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// DSA01008
int n, k, a[100], ok;
void print()
{
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

void init()
{
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

int check() // profiles with exactly k times 1
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 1) cnt++;
    return cnt == k;
}

void next()
{
    int i = n - 1;
    while (i >= 0 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }
    if (i != -1) a[i] = 1;
    else ok = 0;
}

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    int t; cin >> t; 
    while (t--) 
    { 
        cin >> n >> k;
        // B1: khoi tao cau hinh dau tien
        init();
        ok = 1;
        // B2: kiem tra cau hinh cuoi cung, in ra
        while (ok)
        {
            if (check()) 
                print();
            // B3: cau hinh ke tiep
            next();
        }
    } 
    return 0;
}