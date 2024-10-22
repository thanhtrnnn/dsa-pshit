import math, sys

#DSA03025, DSA03024
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n = int(input())
    all = []
    for _ in range(n):
        start, end = map(int, input().split())
        all.append([start, end])
    all.sort(key = lambda line: line[1])
    
    lines, i, j = 0, 0, 0
    while i < n - 1 and j < n - 1:
        for j in range(i + 1, n):
            if all[i][1] <= all[j][0]:
                lines += 1
                i = j
                break
    # add the first line chosen
    print(lines + 1)