#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA05018
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

bool isPalindrome(string str)
{
    int n = str.length();
    forup(i, 0, n / 2)
    {
        if (str[i] != str[n - i - 1])
            return false;
    }
    return true;
}

// O(n^3)
void longest_palindrome(string &s)
{
    // length of longest pali ending in pos 0 -> n-1
    int n = s.length();
    int res = 1;
    // vector<int> dp(n + 1, 1); // unnecessary
    forup(i, 1, n + 1)
    {
        // dp[i] = dp[i - 1];
        forup(j, 0, i)
        {
            string chain = s.substr(j, i - j + 1);
            if (isPalindrome(chain))
                res = max(res, (int)chain.length());
                // dp[i] = max(dp[i], (int)chain.length());
        }
    }
    cout << res << el;
    // cout << dp[n] << el;
}

void dp_pali(string &s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));    
    dp[n - 1][n - 1] = 1;
    fordown(i, n - 2, 0)
    {
        // main diagonal = 1
        dp[i][i] = 1;
        forup(j, i + 1, n)
        {
            if (s[i] == s[j])
                // middle segment + i & j
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    cout << dp[0][n - 1] << el; // n - dp[0][n - 1] for fewest chars deleted to get a pali
}

// O(n^2)
void longestPalSubstr(string &s) 
{
    int n = s.length();
    int start = 0, maxLen = 1;

    // Traverse the input string
    for (int i = 0; i < n; i++) 
    {
        // THIS RUNS TWO TIMES 
        // for both odd and even length palindromes, 
        // j = 0 means odd and j = 1 means even length
        for (int j = 0; j <= 1; j++) 
        {
            int low = i;
            int hi = i + j; 

            // Expand substring while it is a palindrome and in bounds
            while (low >= 0 && hi < n && s[low] == s[hi]) 
            {
                int currLen = hi - low + 1;
                if (currLen > maxLen) 
                {
                    start = low;
                    maxLen = currLen;
                }
                low--;
                hi++;
            }
        }
    }

    cout << maxLen << el;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        string s; cin >> s;
        // longestPalSubstr(s);
        // longest_palindrome(s);
        dp_pali(s);
    }
}