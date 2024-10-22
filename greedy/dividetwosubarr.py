import math, sys

#DSA03005
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    if k < n / 2:
        print(sum(a[k:n]) - sum(a[:k]))
    else:
        print(sum(a[(n - k):n]) - sum(a[:(n - k)]))