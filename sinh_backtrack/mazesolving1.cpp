#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//1317
#define forloop(i, a, b) for (int i = (a); i <= (b); i++)
#define print(a, x, y) forloop(i, x, y) cout << a[i] << " "
#define el "\n"

int n, a[30][30];
char c[1000];
bool sex;
vector<string> all;

void ql(int i,int j,int k){
	if(i==n && j==n){
		for(int i=1;i<k;i++){
			cout<<c[i];
		}
		cout<<" ";
		sex=1;
		return;
	}
	if(i+1<=n && a[i+1][j]==1){
		c[k]='D';
		a[i+1][j]=0;
		ql(i+1,j,k+1);
		a[i+1][j]=1;
	}
	if(j+1<=n && a[i][j+1]==1){
		c[k]='R';
		a[i][j+1]=0;
		ql(i,j+1,k+1);
		a[i][j+1]=1;
	}
}

void backtrack(int row, int col, string s)
{   
    if (row == n && col == n)
    {
        cout << s << " ";
        sex = true;
    }
    // move down behavior
    if (row + 1 <= n && a[row + 1][col] == 1)
        backtrack(row + 1, col, s + "D");
    
    // move right behavior
    if (col + 1 <= n && a[row][col + 1] == 1)
        backtrack(row, col + 1, s + "R");
    
}

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
        cin >> n;
        forloop(i, 1, n)
            forloop(j, 1, n)
                cin >> a[i][j];
        sex = false;
        if (a[1][1] && a[n][n])
            backtrack(1, 1, "");
        if (!sex) // !sex = true, sex = false/ 0
            cout << "-1";
        cout << el;
    }
}