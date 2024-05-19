N = int(input())
v = list(map(int, input().split()))
if N == 1:
    print("A")
    exit(0)
elif N == 2 and v[0] == v[1]:
    print(v[0])
    exit(0)
elif N == 2:
    print("A")
    exit(0)

# 4
# 1 4 13 40
# 1a+b=4(v[1])
# 4a+b=13(v[2]

const = v[2]-v[1] # 27
coef = v[1]-v[0] # 9
if coef == 0:  # 3 3 3같은 경우
    if len(set(v)) == 1:
        print(v[0])
    else:
        print("B")
    exit(0)

if const%coef != 0: # 나누어떨어지지 않는 경우
    print("B")
    exit(0)

a = const//coef # a값 고정
b = v[1]-v[0]*a

# 점검
for i in range(N-1):
    if v[i+1] == a*v[i]+b:
        continue
    else:
        print("B")
        exit(0)

print(v[-1]*a+b)


