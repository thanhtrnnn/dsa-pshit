import math, sys

#CTDL_004
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################
res = 0
def backtrack(deg, pos):
    global res
    for i in range(pos, n):
        if a[i] > a[pos]:
            if deg == k - 1:
                res += 1
            else:
                backtrack(deg + 1, i)

n, k = mint()
a = aint()
for i in range(n - k):
    backtrack(i, 0)
print(res)