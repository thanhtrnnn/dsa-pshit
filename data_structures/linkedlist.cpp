#include <iostream>
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

struct node
{
    int num;
    struct node *next;
    node(): num(0), next(NULL) {};
    node(int x): num(x), next(NULL) {};
    node(int x, node *next): num(x), next(next) {};
};

void input(node *&list, int &n)
{
    node *curr = list;
    forup(i, 0, n)
    {
        int x; cin >> x;
        node *neo = new node(x);
        curr->next = neo;
        curr = curr->next;
    }
}

void printlist(node *&list)
{
    node *curr = list;
    while (curr)
    {
        cout << curr->num << " ";
        curr = curr->next;
    }
    cout << el;
}

void push_front(node *&list, int val)
{
    node *current = new node(val);
    current->next = list;
    list = current;
}

void push_back(node *&list, int val)
{
    node *last = new node(val);
    node *current = list;

    while (current->next != NULL)
        current = current->next;
    current->next = last;
}

void insert(node *&list, int val, int pos)
{
    node *neo = new node(val);
    node *target = list;
    if (pos == 0)
        push_front(list, val);
    else { // else if (pos > 0 && pos <= n)
        forup(i, 1, pos)
            target = target->next;
        neo->next = target->next; // 9 noi voi 3
        target->next = neo; // 2 noi voi 9
    }
}

void pop(node *&list, int pos)
{
    node *target = list;
    if (pos == 0)
        list = target->next;
    forup(i, 1, pos)
        target = target->next;
    target->next = target->next->next;
}

void reverse(node *&list)
{
    node *ptr1, *ptr2, *ptr3;
    // 3 adjacent ptrs
    ptr1 = list; 
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    // setup last 2 ptrs
    ptr1->next = NULL;
    ptr2->next = ptr1;

    while (ptr3 != NULL)
    {
        // touch each nodes from 3 to 2 to 1
        ptr1 = ptr2; 
        ptr2 = ptr3; 
        ptr3 = ptr3->next;
        ptr2->next = ptr1;
    }
    list = ptr2;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        node *list = new node();
        input(list, n);
        printlist(list);
        insert(list->next, 9, 2);
        //pop(list->next, 5);
        // reverse(list->next);
        printlist(list);
    }
}