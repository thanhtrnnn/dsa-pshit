import math, sys

#DSA01007
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

def backtrack(res, s, n, pos):
    if pos == n:
        res.append(s + " ")
        return
    backtrack(res, s + "A", n, pos + 1)
    backtrack(res, s + "B", n, pos + 1)

t = int(input())
for _ in range(t):
    n = int(input())
    res = []
    backtrack(res, "", n, 0)
    print(''.join(res))
    