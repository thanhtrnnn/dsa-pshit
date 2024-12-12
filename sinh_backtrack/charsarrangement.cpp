#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

//DSA02031
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

bool isVowel(char c)
{
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}   

bool vowelsinmid(string s)
{
    int n = s.length();
    forup(i, 0, n)
    {
        if (isVowel(s[i]))
        {
            if (i == 0 || i == n - 1)
                continue;
            else if (!isVowel(s[i - 1]) && !isVowel(s[i + 1]))
                return true;
        }
    }
    return false;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    char c; cin >> c;
    string s;
    for (char x = 'A'; x <= c; x++)
        s += x;
    do {
        if (!vowelsinmid(s))
            cout << s << el;
    }
    while(next_permutation(all(s)));
}