import math, sys

#idhere
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
def printlist(a): print(' '.join(map(str, a)))
def fileio():
    sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
    sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
###############################################

t = nint()
for _ in range(1, t + 1):
    s = input()
    mp = {'H': 1, 'C': 12, 'O': 16}
    stack = [] # mixed parens and val
    i = 0

    while i < len(s):
        c = s[i]
        if c in mp:
            stack.append(mp[c])
        elif c == '(':  
            stack.append('(')
        elif c == ')':
            buf = 0
            while stack and stack[-1] != '(':
                buf += stack.pop()
            stack.pop() # remove (
            stack.append(buf)
        elif c.isdigit():
            mx = int(c)
            last = stack.pop()
            stack.append(last * mx)
        i += 1

    print(f'Test #{_}:', sum(stack))