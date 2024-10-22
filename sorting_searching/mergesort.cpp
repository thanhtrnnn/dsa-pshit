#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06015
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

void merge(vector<int> &a, int left, int mid, int right)
{
    int n1 = mid - left + 1,
        n2 = right - mid;
    vector<int> half1(n1), half2(n2);

    // copy into two halves
    forup(i, 0, n1)
        half1[i] = a[left + i];
    forup(j, 0, n2)
        half2[j] = a[mid + 1 + j];

    // sort & merge back two halves simutaneously
    int i = 0, j = 0, main = left;
    while (i < n1 && j < n2)
    {
        if (half1[i] <= half2[j])
        {
            a[main] = half1[i];
            i++;
        }
        else {
            a[main] = half2[j];
            j++;
        }
        main++;
    }

    // the remains
    while (i < n1)
    {
        a[main] = half1[i];
        i++; main++;
    }
    while (j < n2)
    {
        a[main] = half2[j];
        j++; main++;
    }
}

void mergesort(vector<int> &a, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        vector<int> a(n);
        forup(i, 0, n) cin >> a[i];
        mergesort(a, 0, n - 1);
        print(a, 0, n);
        cout << el;
    }
}