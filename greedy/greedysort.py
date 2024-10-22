import math, sys

#DSA03006
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

def compress(a):
    b = list(sorted(a))
    for i in range(n):
        a[i] = lower_bound(b, a[i])
    return a 

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    alt = compress(a)
    res = True
    for i in range(n // 2):
        if (alt[i] != i or alt[n-i-1] != n-i-1) and (alt[i] != n-i-1 or alt[n-i-1] != i): 
            res = False
    print('Yes' if res else 'No')
