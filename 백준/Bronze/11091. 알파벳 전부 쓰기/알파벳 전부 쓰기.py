for _ in range(int(input())):
    print("missing "+"".join(k) if (k:=sorted({*map(chr,range(97,123))}.difference(set(map(lambda x:x.lower(),filter(lambda x:x.isalpha(),input())))))) else "pangram")