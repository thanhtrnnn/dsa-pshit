#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> cur;

void dfs(int pos, int start) {
    if (pos == k) {
        for (int i = 0; i < k; ++i) {
            if (i) cout << ' ';
            cout << cur[i];
        }
        cout << '\n';
        return;
    }
    for (int v = start; v <= n; ++v) {
        cur[pos] = v;
        dfs(pos + 1, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //các phần tử của a có giá trị ngẫu nhiên
   int a[100];
   //các phần tử trong b lần lượt là 2 8 0 4 2 5
   int b[6] = {2, 8, 0, 4, 2, 5};
   // Mảng char
   char arr[100] = {'2', '8', 't', 'e', 'c', 'h'};
   cout << arr[6] << endl;
   return 0;
}