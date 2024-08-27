from collections import defaultdict
N = int(input())
M = int(input())
d_child = defaultdict(list) # dict[int,list]
d_parent = defaultdict(list) # dict[int,list]
for _ in range(M):
    a,b = map(int,input().split())
    # a > b
    d_child[a].append(b)
    d_parent[b].append(a)


def dfs(node_num: int, visit: set,is_child_mode: bool, is_parent_mode: bool):
    # is_child_mode : 작아지는 방향으로 진행
    visit.add(node_num)
    acc = 0
    if is_child_mode:
        for child in d_child[node_num]:
            if child in visit:
                continue
            acc += 1
            acc += dfs(child,visit,True,False)

    if is_parent_mode:
        for parent in d_parent[node_num]:
            if parent in visit:
                continue
            acc += 1
            acc += dfs(parent,visit,False,True)

    return acc



for number in range(1,N+1):
    visit = set()
    all_visit = dfs(number,visit,True,True)
    print(N-all_visit-1)



