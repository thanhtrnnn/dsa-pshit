#include <bits/stdc++.h>

using namespace std;

#define mod              1000000007
#define ll               long long
#define	p(x)             pair<x,x>
#define v(x)             vector<x>
#define tree             node*
#define sz(a)            a.size()
#define f                first
#define s                second
#define pb(a)            push_back(a)
#define pf(a)            push_front(a)
#define FOR(i,l,r)       for(int i=l;i<r;i++)
#define FORX(i,l,r,x)    for(int i=l;i<r;i+=x)
#define FORD(i,l,r)      for(int i=l;i>=r;i--)
#define correct(x,y,n,m) 0<=(x)&&(x)<(n)&&0<=(y)&&(y)<(m)
#define cin(M,n)         FOR(i,0,n)cin>>M[i]
#define cout(M,n)        FOR(i,0,n)cout<<M[i]<<" "
#define rs(M,x)          memset(M,x,sizeof(M))
#define reset()          FOR(i, 0, 1001)A[i].clear(),check[i]=false
#define faster()         cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()            int t; cin >> t; while (t--)
#define pq(x)            priority_queue<x>
#define neg_pq(x)        priority_queue<x, vector<x>, greater<x>>
#define all(M)           M.begin(),M.end()
#define el               "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

void compress(vector<int> &a) 
{
    set<int> xum(a.begin(), a.end());
    vector<int> b(xum.begin(), xum.end());
    for (int &x: a)
        // index starting from 1
        x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}

vector<int> mark(100);
void decimal_presentation(int a, int b)
{
    cout << a / b << '.'; // Đưa ra phần nguyên trước.

    int pos = 0;
    mark[a % b] = pos++; // Mảng mark lưu vị trí xuất hiện của các số dư.
    a %= b; // Đặt a = a % b để tiếp tục phép chia.

    int loop_start = 0;
    vector <int> quotient; // Vector lưu các thương.
    while (true) // Tiếp tục quá trình chia để tìm các số sau dấu chấm.
    {
        a *= 10;
        ll r = a % b;
        quotient.push_back(a / b);
        if (mark[r]) // Số dư bị lặp lại.
        {
            loop_start = mark[r]; // Vị trí bắt đầu chu kỳ.
            break;
        }
        else // Nếu chưa lặp lại thì tiếp tục chia và lưu số dư.
        {
            mark[r] = pos++;
            a = r; 
        }
    }

    // In ra biểu diễn thập phân của số hữu tỉ a/b.
    for (int i = 0; i < loop_start; ++i)
        cout << quotient[i];
    cout << '(';
    for (int i = loop_start; i < (int)quotient.size(); ++i)
        cout << quotient[i];
    cout << ')';
}

string operator*(string a, int b) 
{
    if (a == "0" || b == 0)
        return "0";
    int n = a.length();
    string c(n, '0');
    int nho = 0;
    for (int i = n - 1; i >= 0; i--) {
        nho += (a[i] - '0') * b;
        c[i] = nho % 10 + '0';
        nho /= 10;
    }
    if (nho > 0)
        c = to_string(nho) + c;
    return c;
}

int main() {
    fileio();
    faster();
	int n; cin >> n;
    cout << (1 << n) << endl;
}

