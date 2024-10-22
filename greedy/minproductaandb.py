import math, sys

#DSA03007
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    if max(a) < max(b):
        a, b = b, a
    a.sort(reverse = True)
    b.sort()

    res = 0
    for i in range(n):
        res += a[i] * b[i]
    print(res)