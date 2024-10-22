#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
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

typedef struct node 
{
    int num;
    struct node *next;
    // node(int x): num(x), next(nullptr) {}
}
node;

node *create(int val)
{
    node *neo = new(node);
    if (neo == NULL)
        return NULL;
    else {
        neo->num = val;
        neo->next = NULL;
        return neo;
    }
}

void push_back(node *&list, int val)
{
    node *last = create(val);
    node *current = list;

    while (current->next != NULL)
        current = current->next;
    current->next = last;
}

void filtered_print(node *&list)
{
    node *ptr = list;
    unordered_set<int> uniq;
    while (ptr != NULL)
    {
        if (uniq.empty() || !uniq.count(ptr->num))
        {
            uniq.insert(ptr->num);
            cout << ptr->num << " ";
        }
        ptr = ptr->next;
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int n, x; 
    cin >> n;
    node *list = new(node);
    forup(i, 0, n)
    {
        cin >> x;
        if (i == 0) 
            list = create(x);
        else
            push_back(list, x);
    }

    filtered_print(list);
}