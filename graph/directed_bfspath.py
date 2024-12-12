import math, sys

#DSA09026
def printlist(a): print(' '.join(map(str, a)))
def fileio():
    sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
    sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################
def add_edge(u, v):
    adj[u].append(v)

def bfs(curr, end, visited):
    # go go
    global res
    queue = []
    queue.append([curr, str(curr)])

    while queue:
        curr_node, curr_path = queue.pop(0)
        visited[curr_node] = True
        for vertex in adj[curr_node]:
            if not visited[vertex]:
                visited[vertex] = True
                if vertex == end:
                    res = curr_path + ' ' + str(vertex) # cay
                queue.append([vertex, curr_path + ' ' + str(vertex)])
                
fileio()
t = nint()
for _ in range(t):
    nodes, edges, start, end = mint()
    adj = [[] for _ in range(nodes + 1)]
    buf = aint()
    pairs = list(zip(buf[::2], buf[1::2]))
    for u, v in pairs:
        add_edge(u, v)

    res = ''
    visited = [False] * (nodes + 1)
    bfs(start, end, visited)
    print(res if len(res) else -1)