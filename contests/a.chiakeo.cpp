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

int n, k, ways, mindiff = 1e9;
vector<int> curr, res;
void backtrack(int pos, int cnt, int sum)
{
    if (sum == k && cnt == n)
    {
        ways++;
        if (curr[0] - curr[n - 1] < mindiff) // update plan
        {
            mindiff = curr[0] - curr[n - 1];
            res = curr;
        }
    }

    for (int j = pos; j >= 1; j--)
    {
        if (sum + j <= k && cnt < n)
        {
            curr.push_back(j);
            backtrack(j, cnt + 1, sum + j);
            curr.pop_back();
        }
    }
}

int cnt, opt; // cnt: số cách chia | opt: chênh lệch tối ưu
int cur[30], f[30]; // cur: trạng thái khi quay lui | f: phương án tối ưu

void run(int id, int k)
{ // xét vị trí id trong trạng thái với số kẹo còn lại là k
    // duyệt các khả năng
    for(int i=min(cur[id - 1], k); i>=1; i--){
        cur[id] = i;
        // trạng thái đã được tạo xong
        if(id == n){
            // kiểm tra trạng thái và cập nhật kết quả
            if(k == i){
                ++cnt;
                if(cur[1] - cur[n] < opt){
                    opt = cur[1] - cur[n];
                    for(int i=1; i<=n; i++) f[i] = cur[i];
                }
            }
        }else run(id + 1, k - i);
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    backtrack(k, 0, 0);
    // run(1, k);
    cout << ways << el;
    print(res, 0, n);
}