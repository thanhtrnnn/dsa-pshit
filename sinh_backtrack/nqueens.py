from itertools import permutations # lib, module 
from time import time
import sys

#idhere
fi = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

def Go(msg = ' ? '):
    if input(msg) == '.': exit(0)

# permutation approach
def Queens(n):
    print('Queen of ', n, ': ') 
    # if n >= 10: 
    #     print('Large Chess Board')
    #     return
    if n < 1: print('dmmm thang cho the anh'); return
    if n == 1: print('(1)'); return
    a = list(range(1, n+1)) # a = [1,..,n]    
    p = permutations(a) # lib
    c = 0
    for x in p: 
        if Sat(x):
            c += 1
            print(c, ':', x) 
    print('Total ', int(c))
    
# x = [1,4,3,2]
# Sat(x) ? 
def Sat(x):
    for i in range(1,len(x)):
        for j in range(i):
            if x[i] == x[j] or i-j == abs(x[i]-x[j]):
                return False
    return True
    
# APPLICATION
for n in range(15):
    t = time()
    Queens(n)
    print('Total time of Queens ', n, ':', time()-t)
    # Go()
print(' T h e   E n d')
