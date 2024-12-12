#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA11001
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

struct node
{
    char c;
    struct node *left, *right;
    node(char neo): c(neo), left(NULL), right(NULL) {};
};

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->c;
    inOrder(root->right);
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        string s; cin >> s;
        stack<node*> st;
        node *root;
        for (char c : s)
        {
            if (!isOperator(c))
                st.push(new node(c));
            else {
                node *opr = new node(c);
                node *c1 = st.top(); st.pop();
                node *c2 = st.top(); st.pop();
                opr->left = c2;
                opr->right = c1;
                st.push(opr);
            }
        }
        root = st.top();
        inOrder(root);
        cout << el;
    }
}