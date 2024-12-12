import bisect
import math, sys

# needs revision
fi = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

def prefixSum(a, n):
    pre = [0] * n
    for i in range(n):
        if (i == 0):
            pre[i] = a[i]
        else:
            pre[i] = pre[i - 1] + a[i]
    return pre

def binary_search(arr, low, high, x):
    if high >= low:
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid

        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, high, x)

    else:
        return -1

t = int(input())
for _ in range(t):
    n, s, k = map(int, input().split())
    a = list(map(int, input().split()))
    pre = prefixSum(a, n)
    
    if (pre[s - 1] <= k):
        print('1')
    else:
        res = bisect.bisect_left(pre, pre[s - 1] - k, lo = 0, hi = s - 1) + 1
        if res == 0 or res == s or res + 1 == s:
            print('-1')
        else:
            print(res + 1)