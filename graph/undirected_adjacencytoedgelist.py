import math, sys

#DSA09002
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

n = nint()
# adjacency matrix
links = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1): 
    for vertex in mint():
        if i != vertex:
            links[i][vertex] = links[vertex][i] = 1

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if links[i][j]:
            print(i, j)
            links[j][i] = 0

# 4
# 1 2 3
# 2 1 3
# 3 1 2 4
# 4 3