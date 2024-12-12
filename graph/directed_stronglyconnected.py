import math, sys

#DSA09010
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
    visited[curr] = True
    for vertex in adj[curr]:
        if not visited[vertex]:
            dfs(vertex, visited)

def isStronglyConnected():
    cnt = 0
    for u in range(1, nodes + 1):
        dup = visited[:(nodes + 1)]
        dfs(u, dup)
        if dup.count(True) == nodes:
            cnt += 1

    return cnt == nodes

fileio()
t = nint()
for _ in range(t):
    nodes, edges = mint()
    buf = aint()
    adj = [[] for _ in range(nodes + 1)]
    pairs = list(zip(buf[::2], buf[1::2]))
    for u, v in pairs:
        add_edge(u, v)
    
    visited = [False] * (nodes + 1)
    print('YES' if isStronglyConnected() else 'NO')