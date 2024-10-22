#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forloop(i, a, b) for (int i = (a); i < (b); i++)

int n, a[15];
long long S, curMoneySum;
vector <int> curMoneySet;

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

void printMoneySet()
{
    for (auto i : curMoneySet) cout << a[i] << " ";
    cout << "\n";
}

//Hàm đệ quy
void genMoneySet(int pos)
{
    int lastIndex = (curMoneySet.empty() ? 1 : curMoneySet.back());
    for (int i = lastIndex; i <= n; i++)
    {
        //Lấy thêm 1 tờ tiền mới vào tập hợp
        curMoneySet.push_back(i);
        curMoneySum += a[i];
        
        //Gọi đệ quy
        if (curMoneySum >= S)
        {
            if (curMoneySum == S) printMoneySet();
        }
        else genMoneySet(pos + 1);
        
        //Bỏ tờ tiền này ra khỏi tập hợp
        curMoneySet.pop_back();
        curMoneySum -= a[i];
    }
}

int main()
{
    fileio();
    cin >> n >> S;
    int coins[n];
    // for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> coins[i];

    int first[S + 5], // construct a solution
        value[S + 5] = {}, // least coins used
        count[S + 5] = {}; // number of solutions
    count[0] = 1;
    
    // value[x] = min(value[x], value[x - c] + 1) (c in coins)
    for (int x = 1; x <= S; x++) 
    {
        value[x] = INT_MAX;
        for (auto c : coins) 
        {
            if (x-c >= 0) 
            {
                count[x] += count[x-c];
                // count[x] %= mod;
                if (value[x - c] + 1 < value[x])
                {
                    value[x] = value[x - c] + 1;
                    first[x] = c;
                }
                
            }
        }
    }

    cout << count[S] << ' ' << value[S] << endl;
    while (S > 0) 
    {
        cout << first[S] << " ";
        S -= first[S];
    }

    // curMoneySet.clear();
    // curMoneySum = 0;
    // genMoneySet(1);

    return 0;
}