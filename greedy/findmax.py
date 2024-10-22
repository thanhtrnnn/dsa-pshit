import enum
import math, sys

#DSA03003
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

mod = int(1e9 + 7)
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    res = 0
    for i, x in enumerate(sorted(a)):
        res = res % mod + (x % mod * i % mod) % mod
    print(res % mod)