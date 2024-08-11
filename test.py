import math, sys, heapq
import random
#idhere
fi = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

from collections import defaultdict
max_heap = []  # Max-heap for the lower half (inverted min-heap)
min_heap = []  # Min-heap for the upper half
delayed = defaultdict(int)
def add(num):
    if not max_heap or num <= -max_heap[0]:
        heapq.heappush(max_heap, -num)
    else:
        heapq.heappush(min_heap, num)
    balance_heaps()

def delete(num):
    delayed[num] += 1
    if num <= -max_heap[0]:
        if num == -max_heap[0]:
            clean_top(max_heap)
        else:
            balance_heaps()
    else:
        if num == min_heap[0]:
            clean_top(min_heap)
        else:
            balance_heaps()

def print_median():
    if not max_heap:
        return None  # Or handle as per your requirement
    return -max_heap[0]

def balance_heaps():
    if len(max_heap) > len(min_heap) + 1:
        heapq.heappush(min_heap, -heapq.heappop(max_heap))
        clean_top(max_heap)
    elif len(min_heap) > len(max_heap):
        heapq.heappush(max_heap, -heapq.heappop(min_heap))
    clean_top(max_heap)
    clean_top(min_heap)

def clean_top(heap):
    while heap and delayed[(-heap[0] if heap is max_heap else heap[0])]:
        num = -heapq.heappop(heap) if heap is max_heap else heapq.heappop(heap)
        delayed[num] -= 1
        if delayed[num] == 0:
            del delayed[num]

def median_maintenance(queries):
    result = []

    for query in queries:
        parts = query.split()
        cmd = parts[0]

        if cmd == "add":
            num = int(parts[1])
            add(num)
        elif cmd == "del":
            num = int(parts[1])
            delete(num)
        elif cmd == "print":
            median = print_median()
            if median is not None:
                result.append(median)

    return result
    
q = int(input())
que = []
for _ in range(q):
    s = input()
    que.append(s)
output = median_maintenance(que)
for val in output:
    print(val)