import math, sys

#DSA05001, DSAKT053
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

# TLE...
t = int(input())
for _ in range(t):
    s1, s2 = input(), input()
    len1 = len(s1)
    len2 = len(s2)

    # You're telling Python to create a list ([0] * (len2 + 1)) 
    # and then repeat it (len1 + 1) times. 
    # However, instead of creating independent lists for each row, 
    # Python creates multiple references to the same list. 
    # This means all the rows in your dp matrix are actually pointing 
    # to the same list in memory.
    # dp = [[0] * (len2 + 1)] * (len1 + 1)
    dp = [[0] * (len2 + 1) for z in range(len1 + 1)]

    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    print(dp[len1][len2])

    # Reconstruct the LCS from the dp table
    res = ''
    while len1 and len2:
        if s1[len1 - 1] == s2[len2 - 1]:
            res = s1[len1 - 1] + res
            len1 -= 1
            len2 -= 1
        elif dp[len1 - 1][len2] > dp[len1][len2 - 1]:
            len1 -= 1
        else:
            len2 -= 1

    print(res)
