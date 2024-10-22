import math, sys

sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

# Class representing an item with value and weight
class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight

# Function to compare items based on value/weight ratio
def item_comparator(a, b):
    r1 = a.value / a.weight
    r2 = b.value / b.weight
    if r1 < r2:
        return -1
    elif r1 > r2:
        return 1
    return 0

# Main greedy function to solve the problem
def fractional_knapsack(W, arr):
    # for x in arr:
    #     print(x.value, x.weight)

    cur_weight = 0  # Current weight in knapsack
    final_value = 0.00  # Result (value in knapsack)

    # Looping through all items
    for item in arr:
        if W == 0:
            break
        if item.weight <= W:
            W -= item.weight
            final_value += item.value
        else:
            final_value += item.value * (W / item.weight)
            W = 0
    
    # for item in arr:
    #     # If adding the item won't overflow, add it completely
    #     if cur_weight + item.weight <= W:
    #         cur_weight += item.weight
    #         final_value += item.value
    #     else:
    #         # If we can't add the current item, add fractional part of it
    #         remain = W - cur_weight
    #         final_value += item.value * (remain / item.weight)
    #         break
    
    # Returning the final value
    return '{:.2f}'.format(final_value)
    # return round(Decimal(final_value), 2)

# Driver code
t = int(input())
for _ in range(t):
    n, mass = map(int, input().split())
    all = []
    for i in range(n):
        price, weight = map(int, input().split())
        all.append(Item(price, weight))
    # Sorting items based on ratio
    all.sort(key=lambda x: x.value / x.weight, reverse = True)
    print(fractional_knapsack(mass, all))