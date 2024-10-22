#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//DSA06009
int twoSum(vector<int> &a, int k)
{
    int n = a.size();
    unordered_multimap<int, int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int pot = k - a[i];
        if (nums.count(pot))
            nums.insert(make_pair(a[i], nums.count(pot)));
        else 
            nums.insert(make_pair(a[i], 0));
    }

    int ans = 0;
    for (auto it : nums)
    {
        cout << it.first << ' ' << it.second << endl;
        ans += it.second;
    }
    return ans;
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
        int n, k; 
        cin >> n >> k;
        vector<int> a;
        for (int i = 0; i < n; i++) 
        {
            int num;
            cin >> num;
            a.push_back(num);
        }
        cout << twoSum(a, k) << endl;
    }

    // int t; cin >> t;
    // while(t--){
    //     int n, k; cin >> n; cin >> k;
    //     vector<int> a(n);
    //     map<int, int> mp;
    //     FOR(i, 0, n) {
    //         cin >> a[i];
    //         mp[a[i]]++;
        
    //         int ans = 0;
    //         for(auto val : a){
    //             if(mp[k - val] != 0){
    //                 ans += (k - val == val) ? mp[k - val] - 1 
    //                                         : mp[k - val];
    //             }
    //         }
    //         cout << ans / 2 << endl;
    //     }
    // }
}