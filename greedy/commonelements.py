import math, sys

#DSA03034
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

t = nint()
for _ in range(t):
    n, m, z = mint()
    a, b, c = aint(), aint(), aint()
    i, j, k = 0, 0, 0
    common = []

    while i < n and j < m and k < z:
        if a[i] == b[j] == c[k]:
            common.append(str(a[i]))
            i += 1
            j += 1
            k += 1
        elif a[i] < b[j]:
            i += 1
        elif b[j] < c[k]:
            j += 1
        else:
            k += 1

    print(' '.join(common) if len(common) != 0 else 'NO')