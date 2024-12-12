#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA7029
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


int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        string s; cin >> s;
        stack<char> st;
        for (char c : s)
        {
            if (c == ']')
            {
                string buf, num, chain;
                // 2 channels
                while (!st.empty() && st.top() != '[')
                {
                    buf = st.top() + buf;
                    st.pop();
                }
                st.pop(); // remove '['
                while (!st.empty() && isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                }
                int times = 1;
                if (size(num))
                    times = stoi(num);

                forup(i, 0, times)
                    chain += buf;
                for (char z : chain)
                    st.push(z);
            }
            else    
                st.push(c);
        }

        string res;
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        cout << res << el;
    }
}