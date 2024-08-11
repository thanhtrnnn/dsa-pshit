import sys, math

fi = open("E:/OneDrive - ptit.edu.vn/pro/cpp/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/cpp/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

n = int(input())
m = int(input())
odds = math.ceil(m / 2)
evens = m - odds

white_col1 = math.ceil(n / 3)
red_col1 = n - white_col1
red_col2 = n // 3
white_col2 = n - red_col2
w = white_col1 + white_col2
r = red_col1 + red_col2

print((m // 2) * w + (m % 2) * white_col1)
print((m // 2) * r + (m % 2) * red_col1)
