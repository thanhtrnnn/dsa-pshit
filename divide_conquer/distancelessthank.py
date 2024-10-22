import math, sys
from bisect import bisect_left

#DSA04023
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    pairs = 0
    for i in range(n):
        pos = bisect_left(a, a[i] + k)
        pairs += pos - i - 1
    print(pairs)