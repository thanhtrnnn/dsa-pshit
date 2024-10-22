from os import remove
import math, sys

#DSA01011
fi = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

def nextPermutation(s):
    if (s == []):
        return False
    n = len(s)
    i, j = 0, 0
    # phase 1: find breaking point
    for i in range (n - 2, -1, -1):
        if s[i] < s[i + 1]: break
        # last profile
        if i == 0:
            s.clear()
            return False
    # phase 2: find superior point j
    for j in range (n - 1, i, -1):
        if s[j] > s[i]: break
    # swapping
    s[i], s[j] = s[j], s[i]
    i, j = i + 1, n - 1
    # reversing
    while i < j:
        s[i], s[j] = s[j], s[i]
        i, j = i + 1, j - 1
    return True

def removeZeros(s):
    for i in range(0, len(s)):
        while s[i] == '0':
            s.pop(i)
        break

t = int(input())
for _ in range(t):
    no, n = input().split()
    s = list(n)

    if not nextPermutation(s):
        print(no, 'BIGGEST')
    else:
        res = ''.join(s)
        print(no, res)
    