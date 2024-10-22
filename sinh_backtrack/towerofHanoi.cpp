#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02029
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define el                  "\n"

int n;
void recursion(int plates, char sent, char receive, char sale)
{
    if (plates == 0) 
        return;
    recursion(plates - 1, sent, sale, receive);
    cout << sent << " -> " << receive << el;
    recursion(plates - 1, sale, receive, sent);

}
void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}


int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    recursion(n, 'A', 'C', 'B');
}