N = int(input())
if N == 1:
    print("A")
    exit(0)

v = list(map(int, input().split()))
if N == 2 and v[0] == v[1]:
    print(v[0])
    exit(0)
elif N == 2:
    print("A")
    exit(0)

assert v.__len__() >=1


answer:set[int] = set()

def dfs(index: int, a: int, b: int,before: int):
    global v
    assert len(v) >= 1
    if index == 0:
        new_before = v[0]
    else:
        # 되는지 점검
        if a*before+b != v[index]:
            return
        new_before =a*before+b

    # 마지막인덱스까지 왔는데 되는 경우
    if index == N-1:
        answer.add(a*new_before+b)
        return

    dfs(index+1,a,b,new_before)

    # for i in range(a+1,101):
    #     for j in range(b+1,101):
    #         dfs(index+1,i,j,new_before)
    pass

for i in range(-100000,100001):
    a = i
    b = v[1] - a*v[0]
    dfs(0,a,b,0)

if not answer:
    print("B")
elif len(answer) >= 2:
    print("A")
else:
    assert len(answer) == 1
    print(list(answer)[0])
