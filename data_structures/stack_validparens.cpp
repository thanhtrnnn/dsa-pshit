#include <iostream>
#include <string>
#include <stack>

using namespace std;

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

bool isValid(string s) 
{
    stack<char> paren;
    for (const char &c : s)
    {
        if (c == '(' || c == '[' || c == '{') 
            paren.push(c);

        else {
            if (paren.empty() ||
                (c == ')' && paren.top() != '(') ||
                (c == ']' && paren.top() != '[') ||
                (c == '}' && paren.top() != '{'))
                    return false;
            paren.pop();
        }
    }

    return paren.empty();
}
class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty();
    }
};

int main()
{
    fileio();
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << (isValid(s) ? "YES" : "NO") << endl;
    }
}