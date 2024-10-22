import math, sys

#DSA05031
def is_perfect_square(x):
    s = int(math.isqrt(x))
    return s * s == x

def lower_bound(nums, target):
    l, r = 0, len(nums) - 1
    while l <= r:
        mid = l + (r - l) // 2
        if nums[mid] >= target:
            r = mid - 1
        else:
            l = mid + 1
    return l

def square_sum():
    # not a suitable candidate list for greedy
    coins = [i * i for i in range(1, 101)]
    dp = [1e7] * 10001
    for i in range(0, 10001):
        if i <= 1:
            dp[i] = i
        else:
            for c in coins:
                if c <= i:
                    dp[i] = min(dp[i], dp[i - c] + 1)
                else:
                    break
    return dp
    
t = int(input())

dp = square_sum()
for _ in range(t):
    n = int(input())
    print(dp[n])
    # greedy - WA
    # res = 0
    # if (not is_perfect_square(n)):
    #     while n > 0:
    #         # find the largest cash smaller than current money
    #         next_cash = lower_bound(a, n)
    #         if a[next_cash] > n:
    #             next_cash -= 1
    #         # update current, res
    #         # print(a[next_cash])
    #         n -= a[next_cash]
    #         res += 1
    # print(1 if res == 0 else res)