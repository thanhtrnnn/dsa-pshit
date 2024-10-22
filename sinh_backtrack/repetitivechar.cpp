#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define el                  "\n"

int n;
void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

void recursion(){
    if() return;
    
}
int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    vector <string> store;
    while(n--){
        string s;
        cin >> s;
        store.push_back(s);
    }
    for(int i = 0;i < store.size();i++){
        for(int j = 0;j < store[i].size();j++){
            if(store[i + 1].find(store[i][j])){

            }
        }
        cout << endl;
    }
}