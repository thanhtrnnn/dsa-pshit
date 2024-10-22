import math, sys

#idhere
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

def Pal_2D(s):
    n = len(s)
    v = [[0]*n for i in range(n)]      
    v[n-1][n-1] = 1
    for i in range(n-2, -1, -1):
        v[i][i] = 1
        for j in range(i+1, n):
            if s[i] == s[j]: 
                v[i][j] = v[i+1][j-1] + 2
            else: 
                v[i][j] = max(v[i][j-1], v[i+1][j]) 
    return n - v[0][n-1]

def Pal(s):
    n = len(s)
    if n == 1:  
        return 0
    a = [1] * n
    for i in range(n - 2, -1, -1):
        c = 0        
        for j in range(i + 1, n):
            d = a[j] # cất tạm phần tử j của dòng dưới
            a[j] = c + 2 if s[i] == s[j] else max(a[j - 1], a[j])
            c = d
    return a[n-1]

t = nint()
for _ in range(t):
    s = input()
    print(Pal(s))