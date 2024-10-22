import math, sys

#DSA03009
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n = int(input())
    all = []
    for i in range(n):
        all.append(list(map(int, input().split())))
    # sort end to ascending order
    all.sort(key = lambda x: x[2], reverse = True)

    occupied = [False] * 1005
    res, i, works = 0, 0, 0
    while i < n:
        for j in range(all[i][1], 0, -1):
            if not occupied[j]:
                res += all[i][2]
                occupied[j] = True
                works += 1
                break
        i += 1

    print(works, res)
    