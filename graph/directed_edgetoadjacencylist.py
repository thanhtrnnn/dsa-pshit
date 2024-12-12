import math, sys

#DSA09003
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################
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
        adj[u].append(v)
    display_graph(adj)
