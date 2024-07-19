
N = int(input())
M = int(input())
visited =set()

rel = dict()  # a,b간의 관계
for n in range(1,N+1):
    rel[n] = set()

for _ in range(M):
    a,b = map(int,input().split())
    rel[a].add(b)
    rel[b].add(a)

def union_find(number: int, group_set: set[int]):
    global visited
    visited.add(number)
    group_set.add(number)
    for friend in rel[number]:
        if friend in visited:
            continue
        union_find(friend, group_set)

# 그룹화 작업
all_group = []
for num in range(1,N+1):
    if num in visited:
        continue
    s = set()
    union_find(num,s)
    all_group.append(s)

best = [] # 대표들

# 그룹 안에서 플로이드 와샬 알고리즘
for group in all_group:
    # 그룹에 한명밖에 없는경우
    if len(group) == 1:
        best.append(list(group)[0])
        continue
    # 플로이드 워셜
    members_list = list(group)
    dist = []
    for _ in range(len(members_list)):
        dist.append([500000]*len(members_list))

    for i in range(len(members_list)):
        for j in range(len(members_list)):
            if i==j:
                dist[i][j]=0
                continue
            mem_num1 = members_list[i]
            mem_num2 = members_list[j]
            if mem_num2 in rel[mem_num1] or mem_num1 in rel[mem_num2]:
                dist[i][j]=1
                dist[j][i]=1

    for i in range(len(members_list)): # 중간
        for j in range(len(members_list)):
            for k in range(len(members_list)):
                if dist[i][k] > dist[i][j] + dist[j][k]:
                    dist[i][k] = dist[i][j] + dist[j][k]



    best_number = -1
    best_dist = 500000
    # 최적의 거리 받기
    for idx in range(len(members_list)):
        real_number = members_list[idx]
        max_dist = 0
        for d in dist[idx]:
            if d >= 500000 or d == 0:
                continue # 무한대는 제외
            max_dist = max(max_dist,d)
        if max_dist < best_dist:
            best_number = real_number
            best_dist = max_dist
    best.append(best_number)



print(len(best))
best.sort()
print(*best,sep="\n")
