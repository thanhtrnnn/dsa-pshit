#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02024
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

int n;
vector<int> a(100);
vector<string> alls;
void backtrack(int i, string s, int count) 
{
	for (int j = i + 1; j <= n; j++) 
    {
		if (a[i] < a[j])
        {
			if (count > 0)
                alls.push_back(s + to_string(a[j]) + " ");
			backtrack(j, s + to_string(a[j]) + " ", count + 1);
		}
	}
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    forup(i, 1, n + 1) cin >> a[i];
    backtrack(0, "", 0); 
    sort(all(alls));
    for (auto x : alls)
        cout << x << el;
}