import math, sys

#DSA05023
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
def printlist(a): print(' '.join(map(str, a)))
###############################################

t = nint()
for _ in range(t):
    n = input()
    res = 0
    for i in range(len(n)):
        for j in range(i, len(n)):
            res += int(n[i:j + 1])
    print(res)