
// LonggVuz
#include<bits/stdc++.h>
using namespace std;
// ☞ Think twice, code once ☜
void End(){
    cerr << "=> Smoothly Finished! Time taken: ";
    cerr << (0.001 * clock()) << "s" << string(25, '\t');
}
#define Sonic() cin.tie(0) -> sync_with_stdio(0)
#define out(x) return cout << x, void()
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define set(a, x) memset(a, x, sizeof(a))
#define bit(a, x) (a >> x & 1)
#define pb push_back
#define is insert
#define el '\n'
#define ld long double
#define int int64_t

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int mxn = 1e6 + 7;

struct node{
    int val;
    node *l, *r;
    node(int x){
        val = x;
        l = r = 0;
    }
};
// chèn một node vào cây
node *ins(node *root, int x){
    if(!root) return new node(x);
    if(x < root->val) root->l = ins(root->l, x);
    else root->r = ins(root->r, x);
    return root;
}
// tìm node nhỏ nhất
node *find(node *root){
    while(root->l) root = root->l;
    return root;
}
// xoá một node trên cây
node *del(node *root, int x){
    // nếu node cần xoá có giá trị nhỏ hơn giá trị node hiện tại
    // suy ra node cần xoá thuộc cây con bên trái của node hiện tại
    if(x < root->val) root->l = del(root->l, x);
    // tương tự với cây con bên phải
    else if(x > root->val) root->r = del(root->r, x);
    // đã tìm thấy node cần xoá
    else{
        // nếu node cần xoá không có cây con bên trái
        // thì ta chỉ cần "nối tiếp" cây con bên phải lên trên
        if(!root->l){
            node *tmp = root->r;
            delete root;
            return tmp;
        }
        // tương tự với cây con bên trái
        if(!root->r){
            node *tmp = root->l;
            delete root;
            return tmp;
        }
        // trường hợp có cả cây con bên trái và phải
        // ta sẽ chọn 1 trong 2 cách đều được
        // 1. tìm node nhỏ nhất của cây con bên phải
        // 2. tìm node lớn nhất của cây con bên trái
        // đây là phương án 1
        node *tmp = find(root->r);
        root->val = tmp->val;
        // sau khi cho node cần tìm thay thế lên node hiện tại
        // thì ta cần xoá bỏ cái node "cần tìm" đó
        root->r = del(root->r, tmp->val);
    }return root;
}

void levelOrder(node *root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *x = q.front(); q.pop();
        cout << x->val << ' ';
        if(x->l) q.push(x->l);
        if(x->r) q.push(x->r);
    }
}

void postOrder(node *root){
    if(!root) return;
    postOrder(root->l);
    postOrder(root->r);
    cout << root->val << ' ';
}

void LonggVuz(){
    int n, q; cin >> n >> q;
    int a[n+5];
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    node *root = NULL;
    for(int i=1; i<=n; i++){
        root = ins(root, a[i]);
    }
    cout << "BST: ";
    levelOrder(root);
    cout << el;
    for(int i=1; i<=q; i++){
        cout << "Query #" << i << ": ";
        string s; cin >> s;
        int x; cin >> x;
        if(s == "ins") root = ins(root, x);
        else root = del(root, x);
        postOrder(root);
        cout << el;
    }
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
    Sonic();

    signed test = 1;
    //cin >> test;
    for(signed i=1; i<=test; i++){
        LonggVuz();
    }

    End();
}
