import math, sys

#DSA05005
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

def upper_bound(arr, target):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if target < arr[mid]:
            r = mid - 1
        else:
            l = mid + 1
    return l

def LISlength2():
    seq = [int(1e9)] * n
    seq[0] = int(-1e9)
    res = 0
    for x in a:
        # why upper_bound?
        # ... no idea
        pos = upper_bound(seq, x)
        if pos < n:
            seq[pos] = x
        res = max(res, pos)
    return res

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print(n - LISlength2())