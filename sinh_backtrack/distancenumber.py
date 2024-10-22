import math, sys
from itertools import permutations

#DSA02033
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

def isValid(a):
    for i in range(len(a) - 1):
        if abs(a[i] - a[i + 1]) == 1:
            return False
    return True

t = nint()
for _ in range(t):
    n = nint()
    if n <= 3:
        continue
    for pot in permutations(range(1, n + 1), n):
        if isValid(list(pot)):
            print(''.join(str(i) for i in pot))