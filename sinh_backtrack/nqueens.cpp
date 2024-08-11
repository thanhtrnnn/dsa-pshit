#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// backtrack approach
#define forloop(i, a, b) for (int i = (a); i < (b); i++)
#define el "\n"

int n, a[100] = {};
bool col[100] = {}, downDiag[100] = {}, upDiag[100] = {};

void print()
{
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << el;
}

void backtrack(int i)
{
    for (int j = 1; j <= n; j++)
    {
        // condition in column & diagonals heading down and up
        // refer to ../ref
        if (!col[j] && !downDiag[i - j + n] && !upDiag[i + j - 1])
        {
            // mark as occupied
            col[j] = downDiag[i - j + n] = upDiag[i + j - 1] = true; 
            a[i] = j;
            if (i == n) 
                print();
            else backtrack(i + 1);
            // mark as available
            col[j] = downDiag[i - j + n] = upDiag[i + j - 1] = false; 
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

    cin >> n;
    backtrack(1);
}