import math, sys

#DSA2021
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################
# COW -> COWWCO -> COWWCOOCOWWC
def find(s, k, lenX):
    if k < len(s):
        # index from 0 -> len(s) - 1
        return s[k]
    if k < lenX // 2:
        # search the left half 
        return find(s, k, lenX // 2)
    elif k == lenX // 2:
        # that two same chars in the middle
        return find(s, k - 1, lenX // 2)
    else:
        # remove the left half & lenX//2 char
        return find(s, k - lenX // 2 - 1, lenX // 2)

t = nint()
for _ in range(t):
    s, k = input().split()
    n = len(s)
    while (n < int(k)):
        n *= 2
    print(find(s, int(k) - 1, n))
