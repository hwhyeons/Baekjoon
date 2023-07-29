while True:
    n = int(input())
    if n == -1:
        break
    v = list(filter(lambda x : n%x==0,list(range(1,n))))
    if sum(v) == n:
        print(f'{n} = {" + ".join(map(str,v))}')
    else:
        print(f'{n} is NOT perfect.')