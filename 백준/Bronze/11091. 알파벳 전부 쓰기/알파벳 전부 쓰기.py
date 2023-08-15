tcnt = int(input())
all={chr(i) for i in range(97,123)}
for _ in range(tcnt):
    s=set(map(lambda x:x.lower(),filter(lambda x:x.isalpha(),input())))
    print("missing "+"".join(k) if (k:=sorted(all.difference(s))) else "pangram")