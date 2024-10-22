import math, sys

#DSA04020
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

def binary_search(a, x):
    left = 0
    right = n - 1
    while left <= right:
        mid = (left + right) // 2
        if a[mid] == x:
            print(mid + 1)
            return
        elif a[mid] < x:
            left = mid + 1 # search the right half
        else:
            right = mid - 1 # search the left half
    print('NO')

t = nint()
for _ in range(t):
    n, k = mint()
    a = aint()
    binary_search(a, k)