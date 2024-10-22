import math, sys

#idhere
fi = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
fo = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
sys.stdin = fi
sys.stdout = fo

hello =  "This is a rather long string containing\n\
several lines of text just as you would do in C.\n\
Note that whitespace at the beginning of the line is\
significant."
s1 = ('ans'.join('bcd'))
s2 = 'BAAAA'
n = 5
k = 3
valid_str = 'A' * k
cnt = 0
for i in range(n - k + 1):
    print(s2[i:(i + k)])
    if s2[i:(i + k + 1)] == valid_str:
        cnt += 1

print(cnt)
