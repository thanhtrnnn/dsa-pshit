import math, sys

#DSA03024, DSA03025
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n = int(input())
    all = []
    for _ in range(n):
        all.append(list(map(int, input().split())))
    # sort end to ascending order
    all.sort(key = lambda x: x[1])

    res = 0
    i = 0
    while i < n - 1:
        current_end_earliest = all[i][1]
        for j in range(i + 1, n):
            start_after_current = all[j][0]
            if (current_end_earliest <= start_after_current):
                res += 1
                i = j
                break
            else:
                i += 1
    print(res + 1)