import sys
from itertools import permutations

#idhere
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdout = fo

def nextPermutation(s):
    if (s == []):
        return False
    n = len(s)
    i, j = 0, 0
    # phase 1: find breaking point
    for i in range (n - 2, -1, -1):
        if s[i] < s[i + 1]: break
        # last profile
        if i == 0:
            s.clear()
            return False
    # phase 2: find superior point j
    for j in range (n - 1, i, -1):
        if s[j] > s[i]: break
    # swapping
    s[i], s[j] = s[j], s[i]
    i, j = i + 1, n - 1
    # reversing
    while i < j:
        s[i], s[j] = s[j], s[i]
        i, j = i + 1, j - 1
    return True
        
def Test1():
    print('Test No 1')
    s = '134763' 
    print(s, end = ' -> ')
    s = list(map(int,s)) 
    if nextPermutation(s):
        print(''.join([str(c) for c in s]))
    else: print('Empty') 
    s = list(map(int,'7654321')) 
    print(s, end = ' -> ')
    if nextPermutation(s):
        print(''.join(map(str, s)))
    else: print('Empty')
           
def Print(d, msg = ''):
    if msg != '': print(msg)
    c = 0
    for x in d: 
        c += 1
        print(c,'.', x)
    
def Test2():    
    print('Test No 2')
    s = [1,2,3,4]    
    print(' All Permutations of ', s) 
    Print(AllPerm(s))    
    
def AllPerm(s):
    p = []
    while len(s) > 0:
        p.append(s.copy())
        if not nextPermutation(s): break
    return p

def GetNextPerm(s): # return w, s bao luu
    w = s.copy()
    if nextPermutation(w): return w
    else: return [] 
    
def GetAllPerm(s):
    p = []
    if s == []: return p    
    while len(s) > 0:
        p.append(s)
        s = GetNextPerm(s)
    return p

def Test3(): 
    print('Test No 3')
    s = [1,2,3]    
    print(' All Permutations of ', s) 
    Print(GetAllPerm(s))     
    
# APPLICATION
Test1()
Test2()
Test3()
d = list(range(1, 5))
p = permutations(d)
for x in p: print(x)
print(' T h e   E n d')
