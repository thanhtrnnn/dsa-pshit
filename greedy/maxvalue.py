import math, sys

#DSA03027
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

n = int(input())
print(sum(2 * i for i in map(int, input().split()) if i > 0))
