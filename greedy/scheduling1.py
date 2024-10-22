import math, sys

#DSA03008
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n = int(input())
    start = list(map(int, input().split()))
    end = list(map(int, input().split()))
    # list with events: start and end timestamp
    all = [[start[i], end[i]] for i in range(n)]
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