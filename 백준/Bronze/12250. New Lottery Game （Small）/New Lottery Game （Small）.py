import itertools
for i in range(int(input())):
    a,b,k = map(int,input().split())
    print(f"Case #{i+1}: {len(list(filter(lambda x: x[0] & x[1] < k, itertools.product(range(0, a), range(0, b)))))}")