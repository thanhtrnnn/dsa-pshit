import math, sys

# 1003
# fi = open("E:/OneDrive - ptit.edu.vn/pro/cpp/dsa/input.txt", mode = 'r')
# fo = open("E:/OneDrive - ptit.edu.vn/pro/cpp/dsa/output.txt", mode = 'w')
# sys.stdin = fi
# sys.stdout = fo

# max = int(1e10)
# prime = [0] * max
# def sieve():
#     prime[0] = prime[1] = 0
#     for i in range(2, max):
#         prime[i] = 1
#     for i in range (2, int(math.sqrt(max))):
#         if (prime[i]):
#             for j in range (i*i, max, i):
#                 prime[j] = 0
def prime(n):
    if n <= 1:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def check(a):
    s = 0
    while a > 0:
        d = a % 10
        if (d != 2 and d != 3 and d != 5 and d != 7): return 0
        s += d
        a //= 10
    return (prime(s))

t = int(input())
for i in range(t):
    start, end = input().split()
    end = int(end) + 1
    cnt = 0
    for j in range(int(start), int(end)):
        if (j == 2 or j % 2 != 0):    
            if (check(j) and prime(j)): 
                cnt += 1
    print(cnt)
    

