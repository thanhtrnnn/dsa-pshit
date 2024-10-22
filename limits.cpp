#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
using ll = long long;

//idhere
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define el                  "\n"

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
    ios::sync_with_stdio(false); cin.tie(0);

    long double number = 2.0L;
    long double epsilon = std::numeric_limits<long double>::epsilon();

    long double sqrt_val = std::sqrt(number);

    // kiểm tra xem căn bậc 2 có đúng trong phạm vi epsilon hay không
    if (std::abs(sqrt_val * sqrt_val - number) < epsilon) {
        std::cout << "Calculation is accurate enough." << std::endl;
    } else {
        std::cout << "Calculation is not accurate enough." << std::endl;
    }
    
    std::cout << "Square root of " << number << " is " << sqrt_val << std::endl;
    return 0;
}