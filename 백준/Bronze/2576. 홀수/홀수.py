v = []
for _ in range(7):
    v.append(int(input()))
v = list(filter(lambda x : x%2, v))
if len(v) == 0:
    print(-1)
else:
    print(sum(v))
    print(min(v))
