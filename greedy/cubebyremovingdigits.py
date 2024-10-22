import math, sys

#1323
fi = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

t = int(input())
for _ in range(t):
    s = input()
    a = []
    for k in range(len(s)):
        for i in range(len(s)):
            tmp = s[:i] + s[(i+k+1):]
            if (tmp != ''):
                pot = int(tmp) ** (1 / 3)
            if abs(round(pot) - pot) <= 0.00001:
                a.append(tmp)
    if (a != []):
        print(max(a))
    else: 
        print('-1')
        