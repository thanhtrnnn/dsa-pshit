import math, sys

#DSA05003
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

def lcs_threestr(x, y, z, a, b, c):
    dp = [[[0 for inn in range(c + 1)]
            for _ in range(b + 1)] 
            for yap in range(a + 1)]
    
    for i in range(1, a + 1):
        for j in range(1, b + 1):
            for k in range(1, c + 1):
                if x[i - 1] == y[j - 1] == z[k - 1]:
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1
                else:
                    dp[i][j][k] = max(dp[i][j][k - 1], dp[i][j - 1][k], dp[i - 1][j][k])

    return dp[a][b][c]
    # i, j = a, b
    # index = dp[a][b]
    # seq = [0] * index
    
    # while i > 0 and j > 0:
    #     if x[i - 1] == y[j - 1]:
    #         seq[index - 1] = x[i - 1]
    #         i -= 1
    #         j -= 1
    #         index -= 1

    #     elif dp[i - 1][j] > dp[i][j - 1]:
    #         i -= 1
    #     else:
    #         j -= 1
    
    # return ''.join(seq)

t = nint()
for _ in range(t):
    a, b, c = mint()
    x, y, z = input().split()
    print(lcs_threestr(x, y, z, a, b, c))