import math, sys

#DSA03022
n = int(input())
a = list(map(int, input().split()))
a.sort(reverse = True)
print(max(a[-1] * a[-2], a[0] * a[1], a[0] * a[-1] * a[-2], a[0] * a[1] * a[2]))
