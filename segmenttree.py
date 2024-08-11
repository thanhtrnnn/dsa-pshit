import math, sys

#idhere
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')


# python3 code for segment tree with sum
# range and update query
A = []
ST = []

def build_segment_tree(arr, tree, node, start, end):
    if start == end:
        tree[node] = (arr[start], -1)
        return

    mid = (start + end) // 2
    build_segment_tree(arr, tree, 2*node+1, start, mid)
    build_segment_tree(arr, tree, 2*node+2, mid+1, end)

    left_max, left_second_max = tree[2*node+1]
    right_max, right_second_max = tree[2*node+2]
    tree[node] = (max(left_max, right_max), max(left_second_max, right_second_max if left_max != right_max else min(left_max, right_second_max)))


def build(node, L, R):
	global A, ST

	# Leaf node where L == R
	if (L == R):
		ST[node] = A[L]

	else:

		# Find the middle element to
		# split the array into two halves
		mid = (L + R) // 2

		# Recursively travel the
		# left half
		build(2 * node, L, mid)

		# Recursively travel the
		# right half
		build(2 * node + 1, mid + 1, R)

		# Storing the sum of both the
		# children into the parent
		ST[node] = ST[2 * node] + ST[2 * node + 1]


def update(node, L, R, idx, val):
	global A, ST

	# Find the lead node and
	# update its value
	if (L == R):
		A[idx] += val
		ST[node] += val

	else:

		# Find the mid
		mid = (L + R) // 2

		# If node value idx is at the
		# left part then update
		# the left part
		if (L <= idx and idx <= mid):
			update(2 * node, L, mid, idx, val)
		else:
			update(2 * node + 1, mid + 1, R, idx, val)

		# Store the information in parents
		ST[node] = ST[2 * node] + ST[2 * node + 1]


def query(node, tl, tr, l, r):
	global A, ST

	# If it lies out of range then
	# return 0
	if (r < tl or tr < l):
		return 0

	# If the node contains the range then
	# return the node value
	if (l <= tl and tr <= r):
		return ST[node]
	tm = (tl + tr) // 2

	# Recursively traverse left and right
	# and find the node
	return query(2 * node, tl, tm, l, r) + query(2 * node + 1, tm + 1, tr, l, r)


# Driver code
n = int(input())
a = list(map(int, input().split()))

# Create a segment tree of size 4*n
ST = [0 for _ in range(4 * n)]

build_segment_tree(a, ST, 0, 0, n - 1)
# Build a segment tree
# build(1, 0, n - 1)
print(ST)
print(f"Sum of values in range 0-4 are: {query(1, 0, n - 1, 0, 4)}")

# Update the value at idx = 1 by
# 100 ths becoming 101
update(1, 0, n - 1, 1, 100)
print("Value at index 1 increased by 100")
print(f"sum of value in range 1-3 are: {query(1, 0, n - 1, 1, 3)}")

# This code is contributed by rakeshsahni
