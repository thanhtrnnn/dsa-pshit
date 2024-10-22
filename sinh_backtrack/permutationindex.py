import math, sys

#DSA01022
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

def perm_toIndex(perm):
    elements = list(range(1, n + 1))
    index = 0
    fac = math.factorial(n - 1)
    
    for i in range(n):
        # considering the profile perm[:i+1]
        rank = elements.index(perm[i])
        # how many profiles from start to current
        index += rank * fac
        elements.pop(rank)
        if i < n - 1:
            fac //= (n - i - 1)
    
    return index + 1

def index_toPerm(idx):
    # reverse thinking
    elements = list(range(1, n + 1))
    perm = []
    idx -= 1 
    fac = math.factorial(n - 1)
    
    for i in range(n):
        rank = idx // fac
        perm.append(str(elements.pop(rank)))
        idx %= fac
        if i < n - 1:
            fac //= (n - i - 1)
    
    return perm

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print(perm_toIndex(a))
    # else:
    #     idx = query[1]
    #     print(' '.join(index_toPerm(idx)))