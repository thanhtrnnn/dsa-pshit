#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02010
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

int n, k;
int sum = 0, ok = 0;
vector<int> a(100), X(100);
vector<vector<int>> res;

void Try2(int sum, int cnt, int pos) // list decreasingly
{
    if (sum == k)
    {
        ok = 1;
        vector<int> tmp;
		forup(i, 1, cnt)
            tmp.push_back(X[i]);
        res.push_back(tmp);
		return;
	}

    for (int j = pos; j <= n; j++)
    {
        if (sum + a[j] <= k)
        {
            X[cnt] = a[j];
            Try2(sum + a[j], cnt + 1, j); // j + 1 for distinct elems
        }
    }
}

// int n, k;
// int M[1000];
// vector<string> S;

// void Try(int sum, int x, string sec) {
// 	forup(i, x, n + 1) {
// 		if (sum == k) {
// 			sec.pop_back();
// 			S.push_back("["+sec+"]");
// 			return;
// 		}
// 		else if (sum < k)
//          Try(sum + M[i], i, sec + to_string(M[i]) + " ");
// 		else return;
// 	}
// }
// int main() {
//     fileio();
// 	faster();
// 	run() {
// 		S.clear();
// 		cin >> n >> k;
// 		FOR(i, 1, n + 1)cin >> M[i];
// 		Try(0, 1, "");
// 		if (S.size() == 0) {
// 			cout << -1 << endl;
// 			continue;
// 		}
// 		for (auto c : S)cout << c << "";
// 		cout << endl;
// 	}
// }

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    tests()
    {
        cin >> n >> k;
        forup(i, 1, n + 1) cin >> a[i];
        Try2(0, 1, 1);

        if (res.size() == 0)
        {
            cout << "-1" << el;
            continue;
        }

        for (auto x : res)
        {
            cout << "[";
            forup(i, 0, (int)x.size())
                (i == (int)x.size() - 1) ? cout << x[i] : cout << x[i] << ' ';
            cout << "]";
        }
        
        res.clear();
        cout << el;
    }
}