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
#define maxn                (int)(1e5 + 7)
#define size(a)             (int)a.size()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

/*
PROBLEM EXPLANATION:
- Taro and Jiro play a game with an array of N integers
- They take turns removing elements from either end of the array
- Taro goes first and wants to maximize X - Y
- Jiro goes second and wants to minimize X - Y  
- X = sum of Taro's elements, Y = sum of Jiro's elements
- Find the value of X - Y when both play optimally

SOLUTION APPROACH:
This is a classic interval DP problem where we need to find the optimal 
difference when both players play optimally on a subarray.

dp[i][j] = optimal value of (Taro's score - Jiro's score) for subarray [i, j]
when it's Taro's turn to play on this subarray.

Base case: dp[i][i] = a[i] (only one element, Taro takes it)

Transition: dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1])
- If Taro takes a[i], the remaining game is [i+1, j] where Jiro plays first
- If Taro takes a[j], the remaining game is [i, j-1] where Jiro plays first
- Since it becomes Jiro's turn, we subtract the optimal value for Jiro
- Taro chooses the option that maximizes his advantage
*/

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    // taro wants max, jiro wants min
    int n; cin >> n;
    vector<int> a(n);
    forup(i, 0, n) cin >> a[i];
    
    // SOLUTION 1: 2D DP - Interval DP approach
    // vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0)); 
    // dp[i][j] = optimal (X - Y) when current player plays on range [i, j]
    
    // Base case: single elements
    // forup(i, 0, n) {
    //     dp[i][i] = a[i];  // If only one element, current player takes it
    // }

    // // Fill DP table for increasing interval lengths
    // fordown(i, n - 1, 0) {        // Start position
    //     forup(j, i + 1, n) {      // End position
    //         // Current player can take either a[i] or a[j]
    //         // After taking, the other player plays optimally on remaining subarray
    //         dp[i][j] = max(
    //             a[i] - dp[i + 1][j],  // Take left element, opponent plays on [i+1, j]
    //             a[j] - dp[i][j - 1]   // Take right element, opponent plays on [i, j-1]
    //         );
    //     }
    // }
    
    // cout << dp[0][n - 1] << el;  // Answer for entire array [0, n-1]

    // SOLUTION 2: 1D DP - Space optimized version
    vector<ll> dp(n, 0); // dp[j] = optimal value for range [0, j]
    forup(i, 0, n) dp[i] = a[i];  // Initialize with single elements

    forup(j, 1, n) {              // For each right boundary
        fordown(i, j - 1, 0) {    // For each left boundary
            dp[i] = max(a[j] - dp[i], a[i] - dp[i + 1]);
            // a[j] - dp[i]: take rightmost, opponent plays optimally on [i, j-1]
            // a[i] - dp[i+1]: take leftmost, opponent plays optimally on [i+1, j]
        }
    }

    cout << dp[0] << el;    // Answer is dp[0] (range [0, n-1])
}