import math, sys

#DSA09001
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################
def add_edge(u, v):
    adj[u].append(v)
    adj[v].append(u)

def display_graph(adj):
    for i in range(1, nodes + 1):
        print(f'{i}: ', end = '')
        for c in adj[i]:
            print(c, end = ' ')
        print()

t = nint()
for _ in range(t):
    nodes, edges = mint()
    adj = [[] for _ in range(nodes + 1)]
    for _ in range(edges): 
        u, v = mint()
        add_edge(u, v)
    display_graph(adj)