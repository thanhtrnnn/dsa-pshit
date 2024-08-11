import math, sys

#1005
fi = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    mp = dict.fromkeys(a, 0) # map<> equivalent - dict
    for i in range (n):
        mp[a[i]] += 1
    for x in mp:
        if (mp[x] % 2):
            print(x)
    