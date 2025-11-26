from os import path
import sys, math

# idhere
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
sint = lambda: map(str, input().split())
aint = lambda: list(map(int, input().split()))
tostr = lambda a: ' '.join(map(str, a))
if path.exists("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt"):
    sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
    sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
###############################################

n, w = mint() # w <= 10^9
weight = []
value = []
xum = 0
for i in range(n):
    x, y = mint()
    weight.append(x)
    value.append(y)
    xum += y # total value of items

# min weight for each value, initially set to w + 1 (impossible)
dp = [w + 1] * (xum + 1)
dp[0] = 0
for i in range(1, n + 1):
    for j in range(xum, -1, -1):
        if dp[j] <= w - weight[i - 1]:
            dp[j + value[i - 1]] = min(dp[j + value[i - 1]], dp[j] + weight[i - 1])

for i in range(xum, -1, -1):
    if dp[i] <= w:
        print(i)
        break