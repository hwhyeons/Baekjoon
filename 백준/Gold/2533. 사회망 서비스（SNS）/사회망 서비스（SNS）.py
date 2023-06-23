import sys
sys.setrecursionlimit(1000001)
input = sys.stdin.readline

n = int(input())
parent = dict()
childs = dict()  # (노드번호 / 자식리스트)
depth = dict()  # (노드번호 / 깊이) -> 깊이 기준은 1번노드가 0
check = dict()

# 아래는 자식 노드를 결정하기 위한 방식
connect = dict()
visit = [False]*1000001

# 1번 노드 부터 깊이 설정
def set_depth(idx, d):
    depth[idx] = d
    if idx in childs:
        for child_idx in childs[idx]:
            set_depth(child_idx, d + 1)


def dfs(idx):
    if idx in childs:  # is child exist
        all_child = childs[idx]
        for child_idx in all_child:
            dfs(child_idx)

        # 모든 자식 노드가 체크가 되어있는 경우
        isAllChildChecked = all(child_idx in check for child_idx in all_child)
        if not isAllChildChecked:
            check[idx] = True
        return
    else:  # no child
        return


def dfs_set_child(idx):
    visit[idx] = True
    child_list = list()
    childs[idx] = child_list
    for con in connect[idx]:
        if visit[con]: # 이미 방문 -> 부모 노드
            continue
        child_list.append(con)
        if con in parent:
            exit(1)
        parent[con] = idx
    for con in child_list:
        dfs_set_child(con)

# 노드 연결
for _ in range(n - 1):
    a, b = map(int, input().split())
    if not a in connect:
        connect[a] = list()
    if not b in connect:
        connect[b] = list()

    connect[a].append(b)
    connect[b].append(a)


# 1번 노드를 기준으로 자식 기준 설정
dfs_set_child(1)
connect = None


# 1번 노드 부터 깊이 설정
set_depth(1, 0)

dfs(1)
print(len(check))
