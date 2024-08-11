#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1315
// goal: creating the largest number/ profile that is smaller than current number.
// (reversed to normal permutation gen)
#define forloop(i, a, b) for (int i = (a); i < (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i]
#define el "\n"

bool ok = true;
void init(vector<int> &a, int n)
{
    forloop(i, 0, n)
        a[i] = n - i; // n = 3 -> 3 - 0, 3 - 1, 3 - 2 -> 321
}

void reversedPermutation(vector<int> &a, int n)
{
    // element next to the last
    int i = n - 2; 
    // when there's increasing part -> dead end for that part
    while (i >= 0 && a[i] < a[i+1]) --i; 

    if (i == -1) ok = false; // stop generating
    else {
        int j = n - 1; // last elem 
        // get an elem that smaller than a[i] then swap, the result
        // is guaranteed to be smaller than current.
        while (a[i] < a[j]) --j; 
        swap(a[i], a[j]);
        // but dont forget the "as largest as possible" principle!
        // reversing the big elems with small ones
        reverse(a.begin() + i + 1, a.end());
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
        vector<int> a(n);
        init(a, n); // first profile
        while (ok) // print only if current profile isnt the last
        {
            print(a, 0, n);
            cout << " ";
            reversedPermutation(a, n); // generate next profile
        }
        ok = true;
        cout << el;
    }
}