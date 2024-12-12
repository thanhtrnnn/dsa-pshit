#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA07018
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; cin.ignore(); while (t--)
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
	int coef, pow;
	node *next;
	node(int x, int y): coef(x), pow(y), next(NULL) {};
};

void addNodes(string s, node *&poly)
{
    int n = s.length();
    node *ptr;
    stringstream m(s);
    string token;
    while (m >> token) 
    {
		int i = token.find("*x^");
        if (i > 0)
        {
            int heso = stoi(token.substr(0, i));
            int somu = stoi(token.substr(i + 3));
    // forup(i, 0, n)
    // {
    //     if (s[i] != '0' && isdigit(s[i]))
    //     {
    //         int heso = 0, somu = 0; 
    //         while (isdigit(s[i]) && i < n)
    //         { 
    //             heso = heso * 10 + s[i] - '0'; 
    //             ++i; 
    //         } 
    //         i += 3; 
    //         while (isdigit(s[i]) && i < n)
    //         { 
    //             somu = somu * 10 + s[i] - '0'; 
    //             ++i; 
    //         }
            if (!poly)
            {
                poly = new node(heso, somu);
                ptr = poly;
            }
            else {
                ptr->next = new node(heso, somu);
                ptr = ptr->next;
            }
        }
    }
}

void bind(node *&poly, node *&ptr, node *&sub)
{
    if (!poly)
    {
        poly = new node(sub->coef, sub->pow);
        ptr = poly;
    }
    else {
        ptr->next = new node(sub->coef, sub->pow);
        ptr = ptr->next;
    }
}

void printlist(node *&list)
{
    node *curr = list;
    string res;
    while (curr)
    {
        res.append(to_string(curr->coef) + "*x^" + to_string(curr->pow) + " + ");
        curr = curr->next;
    }
    res.erase(res.end() - 2);
    cout << res << el;
}

void calcpoly(node *a, node *b)
{
    node *res = NULL, *cur;
    while (a && b)
    {
        if (a->pow > b->pow)
        {
            bind(res, cur, a);
            a = a->next;
        }
        else if (a->pow < b->pow)
        {
            bind(res, cur, b);
            b = b->next;
        }
        else if (a->pow == b->pow)
        {
            a->coef += b->coef;
            bind(res, cur, a);
            a = a->next;
            b = b->next;
        }
    }

    while (a)
    {
        cur->next = new node(a->coef, a->pow);
        cur = cur->next;
        a = a->next;
    }
    while (b)
    {
        cur->next = new node(b->coef, b->pow);
        cur = cur->next;
        b = b->next;
    }

    printlist(res);
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        node *poly1 = NULL, *poly2 = NULL;
        addNodes(s1, poly1);
        addNodes(s2, poly2);
        calcpoly(poly1, poly2);
    }
}