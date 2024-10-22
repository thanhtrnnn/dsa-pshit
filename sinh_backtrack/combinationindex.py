import math, sys
from itertools import combinations

#DSA01023
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

t = nint()
for _ in range(t):
    n, k = mint()
    a = aint()
    idx = 0
    for pot in combinations(list(range(1, n + 1)), k):
        idx += 1
        if list(pot) == a:
            print(idx)
            break
        