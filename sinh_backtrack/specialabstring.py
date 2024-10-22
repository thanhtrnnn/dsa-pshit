import math, sys
from itertools import combinations

#DSA01009
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

def backtrack(res, s, pos):
    if pos == n:
        valid_str = 'A' * k
        cnt = 0
        for i in range(n - k + 1):
            if s[i:(i + k)] == valid_str:
                cnt += 1
        if cnt == 1:
            res.append(s + " ")
        return
    backtrack(res, s + "A", pos + 1)
    backtrack(res, s + "B", pos + 1)

n, k = map(int, input().split())
res = []
backtrack(res, '', 0)
print(len(res))
print('\n'.join(res))