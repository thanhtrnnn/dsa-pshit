#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA01004
#define forloop(i, a, b) for (int i = (a); i < (b); i++)

int n, k;
vector <int> a(50);
vector <int> curSubset;

//Hàm đệ quy
void printSubset()
{
    for (int i : curSubset) cout << i << " ";
    cout << "\n";
}

void genSubset(int pos) // more aesthetic
{
    int lastNum = (curSubset.empty() ? 0 : curSubset.back());  //số cuối cùng được chọn
    for (int i = lastNum + 1; i <= n; i++)
    {
        curSubset.push_back(i);
        if (int(curSubset.size()) == k) printSubset();
        else genSubset(pos + 1);
        curSubset.pop_back();
    }
}

void backtrack(int i)
{
    // max = n - k + i && larger than the prior 
    // -> profiles always increasing
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k)
        {
            for (int i = 1; i <= k; i++) cout << a[i];
            cout << " ";
        }
        else backtrack(i + 1);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--)
    {
        cin >> n >> k;
        curSubset.clear();
        a.clear();
        genSubset(1);
        // backtrack(1);
        cout << endl;
    }
}