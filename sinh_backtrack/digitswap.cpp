#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1319
#define forloop(i, a, b) for (int i = (a); i < (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

void solve(int k, string s)
{   
    int n = s.length();
    forloop(i, 0, n)
    {
        int idx = n - 1;   
        char max = s.back();
        if (!k)
            break;
        forloop(j, i + 1, n)
        {
            if (max <= s[j])
            {
                max = s[j];
                idx = j;
            }
        }
        if (max > s[i])
        {
            swap(s[i], s[idx]);
            --k;
        }
    }
    cout << s << el;
}

void findMaxNumber(string& s, int k, int index, string& maxs) 
{
    // Nếu đã hết lượt hoán đổi hoặc đã duyệt hết xâu
    if (k == 0 || index == s.size()) 
    {
        if (s > maxs) 
            maxs = s;
        return;
    }
    
    char maxChar = s[index];
    int maxIdx = index;
    // Tìm ký tự lớn nhất trong phần còn lại của xâu
    for (int i = index + 1; i < s.size(); i++) {
        // đảm bảo max có ở cuối thì maxIdx sẽ ở cuối
        // chuyển chữ số bé cho chữ số lớn nhất ở cuối -> số lớn nhất có thể
        if (s[i] >= maxChar) {
            maxChar = s[i];
            maxIdx = i;
        }
    }

    // Nếu ký tự lớn nhất không phải là ký tự hiện tại
    if (maxChar != s[index]) 
    {
        // Hoán đổi ký tự
        swap(s[index], s[maxIdx]);
        // Đệ quy để tìm số lớn nhất với số lần hoán đổi còn lại
        findMaxNumber(s, k - 1, index + 1, maxs);
        // Hoán đổi lại để quay lại trạng thái ban đầu
        // backtracking baby
        swap(s[index], s[maxIdx]);
    } 
    else {
        // Nếu ký tự lớn nhất là ký tự hiện tại, tiếp tục với vị trí tiếp theo
        findMaxNumber(s, k, index + 1, maxs);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int k;
        string s;
        cin >> k >> s;
        // solve(k, s);
        string maxs = s;
        findMaxNumber(s, k, 0, maxs);
        cout << maxs << el;
    }
}