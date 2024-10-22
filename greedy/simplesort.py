import math, sys

#DSA03035
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

# actually dp
n = int(input())
a = list(map(int, input().split()))
dp = [0] * (n + 1)
untouched = 0 # more like length of longest consecutive sequence a, a+1, ..., b
for i in range(1, n + 1):
    dp[a[i - 1]] = dp[a[i - 1] - 1] + 1
    untouched = max(untouched, dp[a[i - 1]])
print(n - untouched)