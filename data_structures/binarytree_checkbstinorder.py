import math, sys

#DSA11020
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()[:n]))
###############################################
# inOrder is sorted
t = nint()
for _ in range(t):
    n = nint()
    a = aint()
    print(1 if a == sorted(a) else 0)