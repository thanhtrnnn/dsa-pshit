#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define el "\n"


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
        int n; cin >> n;
        for (int i = 0; i < (1 << n); i++)
        { 
            int val = i ^ (i >> 1); 
            bitset<32> r(val); 
            string s = r.to_string(); 
            cout << s.substr(32 - n) << " ";
        }
        cout << el;
    }
}