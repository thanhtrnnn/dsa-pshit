import math, sys

#DSA05004
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

def lower_bound(arr, target):
    l, r = 0, len(arr) - 1
    while l <= r:
        # mid = l + (r - l) // 2
        mid = (l + r) // 2
        if target <= arr[mid]:
            r = mid - 1
        else:
            l = mid + 1
    return l

# strictly increasing
def LISlength():
    seq = []
    seq.append(a[0])
    for i in range(n):
        # guaranteed to form an incresing seq
        if a[i] > seq[-1]:
            seq.append(a[i])
        # where to put the new boy on seq
        pos = lower_bound(seq, a[i])
        # the small consecutively replace the big
        # not by append, still by directly replacing
        seq[pos] = a[i]
    return len(seq)

n = int(input())
a = list(map(int, input().split()))

# solution 1: dp
# initial value of 1, considering each index
# dp = [1] * n
# for i in range(n):
#     # for j in range(i) acceptable
#     for j in range(i - 1, -1, -1):
#         # if we can form an increasing subsequence containing a[i]
#         if a[j] < a[i]:
#             # longer length... dp[j] + 1 means length at j plus 1 (a[i])
#             dp[i] = max(dp[i], dp[j] + 1)
# print(max(dp))

# solution 2: binary search
print(LISlength())

