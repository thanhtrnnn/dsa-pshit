import heapq
import math, sys

#idhere
fi = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

def find_median(h1, h2):
    if len(h1) == len(h2):
        return -h1[0]
    return -h1[0] if len(h1) > len(h2) else h2[0]

def add_num(num, h1, h2):
    if len(h1) == 0 or num <= -h1[0]:
        heapq.heappush(h1, -num)
    else:
        heapq.heappush(h2, num)

    if len(h1) > len(h2) + 1:
        heapq.heappush(h2, -heapq.heappop(h1))
    if len(h1) < len(h2):
        heapq.heappush(h1, -heapq.heappop(h2))

def remove_num(num, h1, h2):
    if num <= -h1[0]:
        h1.remove(-num)
        heapq.heapify(h1)
    else:
        h2.remove(num)
        heapq.heapify(h2)

    if len(h1) + 1 < len(h2):
        heapq.heappush(h1, -heapq.heappop(h2))
    elif len(h1) > len(h2) + 1:
        heapq.heappush(h2, -heapq.heappop(h1))

# Nhập số lượng truy vấn
Q = int(input())

# Khởi tạo hai heap
h1 = []  # min-heap
h2 = []  # max-heap

# Xử lý các truy vấn
for _ in range(Q):
    query = input().split()
    operation = query[0]
    if operation == 'add':
        num = int(query[1])
        add_num(num, h1, h2)
    elif operation == 'del':
        num = int(query[1])
        remove_num(num, h1, h2)
    else:
        print(find_median(h1, h2))
