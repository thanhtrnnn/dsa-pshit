from itertools import permutations
import math, sys

#DSA02008
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

n, k = mint()
c = []
for _ in range(n):
    c.append(aint())

res = []
for pot in permutations(range(1, n + 1), n):
    sum = 0
    for i in range(n):
        sum += c[i][pot[i] - 1]
    if sum == k:
        res.append(pot)

print(len(res))
for x in res:
    print(' '.join(map(str, x)))    