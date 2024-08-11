import math, sys

# O(n)
# multiset (cpp) O(n log n)
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

n, k = map(int, input().split())
a = list(map(int, input().split()))
deque = []
res = []

# first window
for i in range(k):
    # pop all elems in dq smaller than a[i] ONLY WHEN deque is not empty
    while len(deque) != 0 and a[i] >= a[len(deque) - 1]:
        deque.pop()
    # push_back potential elems
    deque.append(i)
res.append(a[deque[0]])

# slideeee
for i in range(k, n):
    # remove elem out of window, e.g deque = 0 1 2, window = 1 2 3 
    # -> pop_front deque[0]
    if deque[0] <= i - k:
        deque.pop(0)
    # same as first window
    while len(deque) != 0 and a[i] >= a[len(deque) - 1]:
        deque.pop()
    deque.append(i)
    res.append(a[deque[0]])

print(res)