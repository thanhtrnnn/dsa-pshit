import math, sys

#DSA05004
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

def upper_bound(arr, target):
    l, r = 0, len(arr) - 1
    while l <= r:
        # mid = l + (r - l) // 2
        mid = (l + r) // 2
        if target < arr[mid]:
            r = mid - 1
        else:
            l = mid + 1
    return l

# strictly increasing
def LISlength():
    seq = ['a'] * n # int(1e9)
    seq[0] = '@' #int(-1e9)
    res = 0
    for x in a:
        pos = upper_bound(seq, x)
        if pos < n:
            seq[pos] = x
        res = max(res, pos)
    return res

t = int(input())
for _ in range(t):
    n = int(input())
    a = input()

    # solution 1: dp - TLE
    # initial value of 1, considering each index
    # dp = [1] * n
    # for i in range(n):
    #     for j in range(i - 1, -1, -1):
    #         # if we can form an increasing subsequence containing a[i]
    #         if a[j] <= a[i]:
    #             # longer length... dp[j] + 1 means length at j plus 1 (a[i])
    #             dp[i] = max(dp[i], dp[j] + 1)
    # print(max(dp))
    # solution 2: binary search
    print(LISlength())

