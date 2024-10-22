import math, sys

#DSA05026
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

s, n = map(int, input().split())
a = []
for _ in range(n):
    x = int(input())
    a.append(x)

# store the result 0 -> s whether its sum of a subsequence (size >= 1) in a
dp = [0] * (s + 1)
# base case
dp[0] = 1
for i in range(n):
    for j in range(s, a[i] - 1, -1):
        # j - a[i] is either 0 (j = a[i], a seq size 1) or > 0 (seq size > 1)
        # it still implies j is in a subseq
        if dp[j - a[i]]:
            # mark j in dp
            dp[j] = 1

for x in range(s, 0, -1):
    if dp[x]:
        # the first sum of seq we meet from s -> the biggest
        print(x)
        break
# or print dp[s] to check a seq having the sum of s (ref to sumofsubsequence.cpp)