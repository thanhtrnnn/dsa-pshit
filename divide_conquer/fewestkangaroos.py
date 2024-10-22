import math, sys
from bisect import bisect_right

#DSA04013
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    fewest = n
    left, right = 0, n // 2
    a.sort(reverse = True)
    while left < n // 2 and right < n:
        if a[left] >= 2 * a[right]:
            fewest -= 1
            left += 1
            right += 1
        else:
            right += 1
    print(fewest)