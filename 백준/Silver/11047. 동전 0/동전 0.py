
ans =0
acc = 0
N,K = map(int,input().split())
v: list[int] = []
for _ in range(N):
    v.append(int(input()))
v.reverse()

i = 0
while True:
    val = v[i]
    if acc + val > K:
        i+=1
        continue
    left = K - acc # 남은 양
    q = left//val # 몇개까지 가능한지 (예를들어 200원 남았는데 60원 동전이면 3개 가능)
    use = q*val # 실제 얼마쓸지
    ans+=q
    acc+=use
    if acc == K:
        break

print(ans)
