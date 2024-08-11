#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forloop(i, a, b) for (int i = (a); i < (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int n, k, s;
int cursum = 0, res = 0;
int curset[10];

// note: j can be replaced by a[j], where a[i] = i, i: 1 -> n
// why? see sumofsubset.cpp
// standard backtrack
void moneyset(int last, int cnt) // can take 3 params like solution 2
{
    // candidates in range [(1 + last elem from root branch), n]
    // first branch [1, n]
    for (int j = last; j <= n; j++)
    {
        // instinct, right?
        if (j + cursum <= s)
        {
            // add to result array & update current sum
            curset[cnt] = j;
            cursum += j;
            // print the satisfied profile and add 1 to res
            if (cnt == k - 1 && cursum == s)
            {
                // print(curset, 0, cnt);
                // cout << el;
                ++res;
            }
            // continue in next branch with a bigger starting point of candidates (j + 1)
            // and the next position aka updated number of elems in curset (cnt + 1)
            else moneyset(j + 1, cnt + 1);
            cursum -= j;
        }
    }
}

// branch n bound baby
void backtrack (int pos, int cnt, int sum)
{
    // same as sol. 1, but END THE BACKTRACK BRANCH
	if(cnt == k && sum == s)
    {
		// print(curset, 0, cnt);
        // cout << el;
		++res;
		return;
	}

    // lamo same
	for (int j = pos; j <= n; j++)
    {
		if (j + sum <= s)
        {
			curset[cnt] = j;
            // update all 3 params (cursum = sum + j)
			backtrack(j+1, cnt+1, sum+j);
		}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false); cin.tie(0);

    while (cin >> n >> k >> s)
    {
        memset(curset, 0, sizeof(curset));
        res = 0;
        if (n == 0 && k == 0 && s == 0)
            break;
        // begin with our little 1 as first candidate
        // cnt sure 0
        moneyset(1, 0);
        // this too, sum = cnt = 0
        // backtrack(1, 0, 0);
        cout << res << el;
    }
}