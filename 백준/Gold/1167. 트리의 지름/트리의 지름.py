import math
fd = open(0)
n = int(fd.readline().strip())

nodes = dict() # key : node number / value : list
max_val_dict = dict()
parent_acc_dict = dict()

# def renew_acc(cur: int,new_acc: int):
#     # renew max_value
#     if new_acc > max_val_dict[cur][0]:
#         before_best = max_val_dict[cur][0]
#         max_val_dict[cur][0] = new_acc
#         max_val_dict[cur][1] = before_best  # 2번째 큰 대상을 기존껄로 대체
#     elif new_acc > max_val_dict[cur][1]:
#         max_val_dict[cur][1] = new_acc

def dfs(cur: int, parent: int, dist_parent: int ,acc: int):
    # parent : dfs()로 나를 호출한 노드 (루트는 -1)
    # dist_with_parent : 부모노드와 나 사이의 거리
    global max_val_dict, nodes

    my_nbs = nodes[cur]
    if not cur in max_val_dict:
        max_val_dict[cur] = [-math.inf,-math.inf] # 존재 X

    # # parent exist -> 부모 노드까지 온 값 갱신
    # if parent > 0:
    #     renew_acc(cur, dist_with_parent)
    # else: # no parent
    #     # 부모 노드가 없는 경우 시작노드만 해당
    #     assert parent == -1 and cur == 1

    parent_acc_dict[cur] = acc
    neighbor_dists = []
    for nb in my_nbs:
        nb_num = nb[0]
        nb_dist = nb[1]
        if nb_num == parent: # 자신을 호출한 부모 노드일 때
            continue
        new_acc = dfs(nb_num, cur, nb_dist,nb_dist + acc)
        # max_nb_dist = max(new_acc,max_nb_dist)
        neighbor_dists.append(new_acc)
        # renew_acc(cur,new_acc)
    neighbor_dists.sort(reverse=True)
    if len(neighbor_dists) == 0:
        neighbor_dists.append(0)
    if len(neighbor_dists) == 1:
        neighbor_dists.append(0)
    max_val_dict[cur] = [neighbor_dists[0],neighbor_dists[1]]
    return max(neighbor_dists)+dist_parent

    # neighbor_dists.sort(reverse=True)
    # assert not (max_val_dict[cur][0] < 0 and max_val_dict[cur][1] < 0)
    # if not neighbor_dists:
    #     max_val_dict[cur][0] = acc
    #     max_val_dict[cur][1] = 0
    #     return acc
    # else:
    #     max_val_dict[cur][0] = max(acc, neighbor_dists[0])
    #     if len(neighbor_dists) == 1:
    #         max_val_dict[cur][1] = min(acc, neighbor_dists[0])
    #     else:
    #         max_val_dict[cur][1] = max(acc, neighbor_dists[1])
    #     return neighbor_dists[0]+dist_parent
    # if max_val_dict[cur][0] < 0:
    #     return max_val_dict[cur][1]
    # elif max_val_dict[cur][1] < 0:
    #     return max_val_dict[cur][0]
    # else:
    #     이 둘을 더한게 아님.. 부모는 제외..
    #     return max_val_dict[cur][0]+max_val_dict[cur][1]



for _ in range(n):
    line: list = list(map(int, fd.readline().split()))[:-1]
    cur_node_number = line[0]
    assert not cur_node_number in nodes
    nb_list: list[tuple[int,int]] = []  # list[nodeNumber, dist]
    for i in range(1,len(line),2):
        nb = line[i]  # 이웃
        nb_dist = line[i+1]
        nb_list.append((nb,nb_dist))
    nodes[cur_node_number] = nb_list

start_node_num = 1

dfs(1,-1,0,0)

# TODO : 최종적으로 계산할 떄, 한 노드의 max_path중에 1개가 inf면 더하기 하지말고 그냥 한놈 큰거 고르기

max_answer = -math.inf
for node_num,tps in max_val_dict.items():
    max_val1,max_val2 = tps
    if max_val1 < 0:
        max_answer = max(max_answer,max_val2)
    elif max_val2 < 0:
        max_answer = max(max_answer,max_val1)
    else:
        max_answer = max(max_answer,max_val1+max_val2)

print(max_answer)
# print("----")
# print(max_val_dict)
# print("----parent----")
# print(parent_acc_dict)



