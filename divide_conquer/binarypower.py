import math, sys

#DSA04001
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

def binpow(n, k): # 2 5
    mod = (int)(1e9 + 7)
    res = 1
    while k != 0:
        # 5 % 2
        if k % 2:
            # res = 1 * 2
            # res = 2 * 2^4 = 2^5
            res = res * n % mod
        # k = 5 // 2 = 2
        # k = 2 // 2 = 1
        k //= 2
        # n = 2^2
        # n = 2^4
        n = n * n % mod
    return res % mod

def recursion_binpow(n, k):
    mod = (int)(1e9 + 7)
    if k == 1:
        return n
    res = recursion_binpow(n, k // 2)
    if k % 2:
        return res * res * n % mod
    else:
        return res * res % mod

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    #print(recursion_binpow(n, m))
    print(binpow(n, m)) 