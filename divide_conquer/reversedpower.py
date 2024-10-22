import math, sys

#DSA04002
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
mod = (int)(1e9 + 7)
###############################################

def binpow(n, k):
    if k == 1:
        return n
    res = 1
    while k > 0:
        if k % 2:
            res *= n
        k //= 2
        n *= n
    return res % mod

def reversednum(n):
    rev = 0
    while n > 0:
        rev = n % 10 + rev * 10
        n //= 10
    return rev

t = nint()
for _ in range(t):
    n = nint()
    print(binpow(n, reversednum(n)))

    # n = input()
    # r = ''.join(reversed(n))
    # print(binpow(int(n), int(r)))

    # n = nint()
    # print(n ** reversednum(n) % mod)
