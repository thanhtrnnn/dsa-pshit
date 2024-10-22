#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06014
#define forloop(i, a, b) for (int i = (a); i < (b); i++)

vector<bool> isPrime;
void sieve(int n) 
{
    isPrime.push_back(false);
    isPrime.push_back(false);
    for (int i = 2; i <= n; i++) 
        isPrime.push_back(true);
    for (int i = 2; i * i <= n; i++) 
    {
        if (isPrime[i]) 
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

pair<int, int> prime_twoSum(int n)
{
    if (isPrime[n-2]) return {2, n-2};
    for (int i = 3; i < n; i += 2)
    {
        if(isPrime[i] && isPrime[n-i])
            return {i, n-i};
    }
    return {};
}

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

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        sieve(n);
        pair<int, int> res = prime_twoSum(n);
        if (res.first != 0)
            cout << res.first << " " << res.second << endl;
        else    
            cout << "-1" << endl;
        isPrime.clear();
    }
}