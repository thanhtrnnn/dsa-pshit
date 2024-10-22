import math, sys

#idhere
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

def prefixSum():
    pre = [0] * n
    pre[0] = a[id[0]]
    for i in range(1, n):
        pre[i] = pre[i - 1] + a[id[i]]
    return pre

n = int(input())
a = list(map(int, input().split()))
id = list(range(n))
id.sort(key = lambda i: a[i])

pre = prefixSum()
for x in id:
    print(x + 1, pre[x - 1])
print(pre[-1])
