p,k = map(int,input().split())

# if k>=p:
#     print("GOOD")

for i in range(2,k+1):
    if p%i == 0:
        if i < k:
            print(f"BAD {i}")
            exit(0)
print("GOOD")