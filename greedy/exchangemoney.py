import math, sys

#DSA03001
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

def lower_bound(nums, target):
    l, r = 0, len(nums) - 1
    while l <= r:
        mid = l + (r - l) // 2
        if nums[mid] >= target:
            r = mid - 1
        else:
            l = mid + 1
    return l

t = int(input())
# can apply greedy only when
#  a[i] >= 2 * a[i - 1]
a = [1, 2, 5, 10, 20, 50, 100, 200, 500, 1000]

for _ in range(t):
    n = int(input())
    # min numbers of cash
    # first calc numbers of biggest cash
    res = n // 1000
    n -= res * 1000
    while n > 0:
        # find the largest cash smaller than current money
        next_cash = lower_bound(a, n)
        if a[next_cash] > n:
            next_cash -= 1
        # update current, res
        n -= a[next_cash]
        res += 1
    print(res)