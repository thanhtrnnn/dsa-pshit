#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA04016
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

int merge(vector<int> &half1, vector<int> &half2, int n1, int n2, int target)
{
    // sort & merge back two halves simutaneously
    int i = 0, j = 0, main = 0, res;
    while (i < n1 && j < n2 && main < target)
    {
        if (half1[i] <= half2[j])
        {
            res = half1[i];
            i++;
        }
        else {
            res = half2[j];
            j++;
        }
        main++;
    }

    // the remains
    while (i < n1 && main < target)
    {
        res = half1[i];
        i++;
        main++;
    }
    while (j < n2 && main < target)
    {
        res = half2[j];
        j++; 
        main++;
    }

    return res;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int m, n, k; 
        cin >> m >> n >> k;
        vector<int> a(m), b(n);
        forup(i, 0, m) cin >> a[i];
        forup(i, 0, n) cin >> b[i];
        cout << merge(a, b, m, n, k) << el;        
    }
}