import sys
mod = int(1e9 + 7)

#1327
fi = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

class matrix:
    a = []
    def __init__(self, arr):
        self.a = arr
    
def matproduct (x, y):
    c = matrix([[0, 0], [0, 0]])
    for i in range (0, 2):
        for j in range(0, 2):
            for k in range (0, 2):
                c.a[i][j] += x.a[i][k] * y.a[k][j]
                c.a[i][j] %= mod
    return c

def binpow (mat, n):
    # equivalent to res = 1
    res = matrix([[1, 0], [0, 1]])
    # right shift bits till no bits left
    while (n != 0):
        # multiply res to mat only when last bit of n = 1
        if (n % 2):
            res = matproduct(res, mat)
        # n /= 2
        n >>= 1
        # mat^2 
        mat = matproduct(mat, mat)
    return res

t = int(input()) 
for _ in range(t):
    # check ref
    arr = matrix([[1, 1], [1, 0]])
    n = int(input())
    res = binpow(arr, n)
    print(res.a[0][1])
