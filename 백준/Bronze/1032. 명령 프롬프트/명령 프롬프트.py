t=int(input())
v=[input() for _ in range(t)]
v=list(map(list,zip(*v)))
print("".join(map(lambda x: x[0] if len(set(x)) == 1 else "?", v)))