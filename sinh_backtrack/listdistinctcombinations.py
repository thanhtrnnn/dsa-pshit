from itertools import combinations 

#DSA01028
def list_combinations(): 
    unique_elements = sorted(set(A)) 
    combs = combinations(unique_elements, K) 
    for x in combs: 
        print(" ".join(map(str, x))) 

N, K = map(int, input().split()) 
A = list(map(int, input().split())) 
list_combinations()