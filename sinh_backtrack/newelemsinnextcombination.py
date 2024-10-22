import math, sys
from itertools import combinations

#DSA01021, DSA01010
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

curSubset = []
cnt = 0
a = []
n = 0
k = 0
done = False

def newElementsinnextCombination():
    global a, cnt, done
    cnt = 0
    i = k - 1
    
    # Find the first position from the right that can be incremented
    while i >= 0 and a[i] == n - k + i + 1:
        i -= 1
    
    # If no position can be incremented, we are done
    if i < 0:
        done = True
        return k
    
    # Increment the found position
    a[i] += 1
    
    # Reset the elements after it to the smallest possible values
    for j in range(i + 1, k):
        a[j] = a[j - 1] + 1
    
    # Count the differences between the old and new combinations
    for x in a:
        if (not x in curSubset):
            cnt += 1
    
    # Print the new combination and count
    return cnt

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    curSubset = a.copy()
    print(newElementsinnextCombination())
    done = False