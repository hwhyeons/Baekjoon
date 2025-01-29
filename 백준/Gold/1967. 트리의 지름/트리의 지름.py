import sys
sys.setrecursionlimit(100000)

max_answer: int = 0

class Node:
    def __init__(self, num: int) -> None:
        self.num = num
        self.child_list: list[tuple[int,int]] = [] # node_number / weight

node_list: list[Node] = []


def dfs(num: int) -> int:
    global max_answer
    child_answer = [0,0]
    cur_node: Node = node_list[num]
    for child_num,child_weight in cur_node.child_list:
        child_local = child_weight + dfs(child_num)
        child_answer.append(child_local)


    # max_answer = max(max_answer,자식노드쌍에서제일큰값)->자식이2개이하인경우;
    child_answer.sort(reverse=True)
    max_answer = max(max_answer,child_answer[0]+child_answer[1]) # 자식 노드 두쌍으로 연결된 경우
    return_answer = child_answer[0] # 한줄짜리 최대값
    max_answer = max(max_answer,return_answer)
    # print("max : ",max_answer)
    # max_answer갱신;
    return return_answer



n = int(input())
node_list.append(None) # 0번 인덱스
for i in range(1,n+1):
    node = Node(i)
    node_list.append(node)

for i in range(1,n):
    p,c,w = map(int,input().split())
    parent_node: Node = node_list[p]
    parent_node.child_list.append((c,w))
d1 = dfs(1)
print(max(max_answer,d1))
