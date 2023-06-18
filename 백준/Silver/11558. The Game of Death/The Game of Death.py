tcnt = int(input())
for i in range(tcnt):
    n = int(input())
    lst = []
    for j in range(n):
        lst.append(int(input()))

    st = set()
    cur = 0
    ans = 1
    while True:
        st.add(cur)
        nextIndex = lst[cur]-1
        if nextIndex == n-1:
            break
        if nextIndex in st:
            ans = 0
            break
        cur = nextIndex
        ans+=1
    print(ans)




