import math, sys

#DSA09022
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
def printlist(a): print(' '.join(map(str, a)))
def fileio():
    sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
    sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
###############################################
def add_edge(u, v):
    adj[u].append(v)

def dfs(curr, visited):
    # go go
    print(curr, end = ' ')
    visited[curr] = True
    for vertex in adj[curr]:
        if not visited[vertex]:
            dfs(vertex, visited)

fileio()
t = nint()
for _ in range(t):
    nodes, edges, start = mint()
    adj = [[] for _ in range(nodes + 1)]
    buf = aint()
    pairs = list(zip(buf[::2], buf[1::2]))
    for u, v in pairs:
        add_edge(u, v)
    visited = [False] * 1001
    dfs(start, visited)
    print()