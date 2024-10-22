import math, sys

#DSA03004
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    num1, num2, j = 0, 0, 0
    for i, x in enumerate(sorted(a)):
        if i % 2:
            num1 = num1 * 10 + x
        else:
            num2 = num2 * 10 + x

    print(num1 + num2)