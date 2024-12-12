import math, sys

#DSA09027
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
    adj[v].append(u)

def DFS(curr, visited):
    # go go
    visited[curr] = True
    for vertex in adj[curr]:
        if not visited[vertex]:
            DFS(vertex, visited)

fileio()
t = nint()
for _ in range(t):
    nodes, edges = mint()
    adj = [[] for _ in range(nodes + 1)]
    for i in range(edges):
        u, v = mint()
        add_edge(u, v)

    visited = [False] * (nodes + 1)
    q = nint()
    for _ in range(q):
        start, end = mint()
        rep = visited.copy()
        DFS(start, rep)
        print('YES' if rep[end] else 'NO')