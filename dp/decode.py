import math, sys

#DSA05029
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    m = input()
    # how many profiles with each lengths
    dp = [0] * (len(m) + 1)
    # base case
    # actually when m[0] == '0' dp[1] should be 0 (implement on print())
    dp[0] = dp[1] = 1
    # dp starts building from 2 -> len(m)
    # m index from 1 -> len(m) - 1
    for i in range(2, len(m) + 1):
        # cant form a profile with a seperate 0 in it
        if m[i - 1] != '0':
            dp[i] = dp[i - 1]
        # when a valid chain, add
        if m[i - 2] == '1' or m[i - 2] == '2' and m[i - 1] <= '6':
            dp[i] += dp[i - 2]

        # example:
        # 11234, i = 4
        # º dp[4] = dp[3] = 3
        # profiles:
        #   1 1 2 + 3
        #   11  2 + 3
        #   1  12 + 3
        # º dp[4] += dp[2], valid chain = '23'
        # profiles:
        #   1 1 + 23
        #   11  + 23
        # º final: dp[4] = 5
        
    print(dp[-1] if m[0] != '0' else '0')