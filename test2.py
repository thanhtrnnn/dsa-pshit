import math, sys

#idhere
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################
# Defining the range
start, end = mint()
a, b, c = mint()
# Helper function to count multiples of a number in the given range
def count_multiples(n, start, end):
    return end // n - (start - 1) // n

# Count multiples of 6, 7, 8
count_a = count_multiples(a, start, end)
count_b = count_multiples(b, start, end)
count_c = count_multiples(c, start, end)

# Count multiples of least common multiples (LCM)
count_ab = count_multiples(math.lcm(a, b), start, end)  # LCM(6, 7)
count_ac = count_multiples(math.lcm(a, c), start, end)  # LCM(6, 8)
count_bc = count_multiples(math.lcm(b, c), start, end)  # LCM(7, 8)

# Count multiples of LCM(6, 7, 8)
count_abc = count_multiples(math.lcm(a, b, c), start, end)  # LCM(6, 7, 8)

# Applying the inclusion-exclusion principle
total_multiples = (count_a + count_b + count_c
                   - count_ab - count_ac - count_bc 
                   + count_abc)

# Total numbers in the range [5000, 10000]
total_numbers = end - start + 1

# Numbers not divisible by 6, 7, or 8
result = total_numbers - total_multiples
print(result)

