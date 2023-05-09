"""
Alice and Bob are batch mates and Alice got placed in a well-reputed
product-based company and his friend Bob is demanding a pizza party 
from him. Alice is ready for giving party and he ordered N pizzas 
from the nearest restaurant. Now pizzas can have at most K different
flavors (It is not necessary that there should be one pizza of each flavor)
, numbered from 1 to K such that ith pizza can have Ai flavor (1 <= Ai <=k).

Bob is on dieting, and he can only eat pizza of at most k-1 flavors but
he can eat as many pizzas of ith flavor and he wanted to choose maximum 
possible pizzas which are in contiguous sequence to one another 
such that all pizzas in sequence has atmost k-1 flavors.

for example:
6 2
1 1 1 2 2 1

maxmium length of the subarray such that subarray has
atmost k - 1 distnict flavors is 3 and that subarray is
1 1 1
"""

def max_pizzas(n, k, a):
    max_window_size = 0
    left = 0
    flavors_count = {}
    
    for right in range(n):
        if a[right] not in flavors_count:
            flavors_count[a[right]] = 1
        else:
            flavors_count[a[right]] += 1
            
        while len(flavors_count) > k-1:
            flavors_count[a[left]] -= 1
            if flavors_count[a[left]] == 0:
                del flavors_count[a[left]]
            left += 1
        
        max_window_size = max(max_window_size, right-left+1)
    
    return max_window_size
    
n, k = map(int, input().split())
a = list(map(int, input().split()))
print(max_pizzas(n, k, a))
