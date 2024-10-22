import math, sys

#CTDL_001
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

def backtrack(res, s, n, pos):
    if pos == n:
        if s[:] == s[::-1]:
            res.append(' '.join(s) + " ")
        return
    backtrack(res, s + "0", n, pos + 1)
    backtrack(res, s + "1", n, pos + 1)

n = int(input())
res = []
backtrack(res, '', n, 0)
print('\n'.join(res))