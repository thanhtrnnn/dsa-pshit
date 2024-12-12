#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
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

vector<int> fibo(50), countA(50); // len of each f(n)
int countAinfirstK(int n, int k)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    if (k <= fibo[n - 1])
        return countAinfirstK(n - 1, k);
    else
        return countA[n - 1] + countAinfirstK(n - 2, k - fibo[n - 1]);
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    fibo[0] = fibo[1] = 1;
    countA[0] = 1;
    countA[1] = 0;
    forup(i, 2, 46)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        countA[i] = countA[i - 1] + countA[i - 2];
    }

    tests()
    {
        int n, k; 
        cin >> n >> k;
        cout << countAinfirstK(n, k) << el;
    }
}