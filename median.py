import math, sys, re, heapq

#1548
fi = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

q = int(input())
maxheap = []
minheap = []

# python supports minheap only -> creating maxheap by using neg values
for _ in range(q):
    s = input()
    parts = s.split()
    
    # parts[0] == 'add'
    if re.match(r"^add \d+$", s): 
        elem = int(parts[1])
        if len(maxheap) == 0 or elem <= -maxheap[0]:
            heapq.heappush(maxheap, -elem)
        else:
            heapq.heappush(minheap, elem)
        
        if len(maxheap) > len(minheap) + 1:
            heapq.heappush(minheap, -heapq.heappop(maxheap))
        elif len(minheap) > len(maxheap):
                heapq.heappush(maxheap, -heapq.heappop(minheap))
            
    # parts[0] == 'del'
    elif re.match(r"^del \d+$", s): 
        elem = int(parts[1])
        if elem <= -maxheap[0]:
            maxheap.remove(-elem)
            heapq.heapify(maxheap)
        else:
            minheap.remove(elem)
            heapq.heapify(minheap)

        if len(maxheap) > len(minheap) + 1:
            heapq.heappush(minheap, -heapq.heappop(maxheap))
        elif len(minheap) > len(maxheap):
                heapq.heappush(maxheap, -heapq.heappop(minheap))

    else:
        print(-maxheap[0])
        # print(maxheap, minheap)