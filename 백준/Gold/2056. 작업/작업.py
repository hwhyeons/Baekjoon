import math
N = int(input())
dp = [0]*(N+1) # 최대값 배열 (최소값 아님!!)
visit = [False]*(N+1) # 방문 체크 배열

class Node:
    def __init__(self,weight: int):
        self.weight = weight # 현재 노드를 수행하는데 걸리는 시간
        self.adjs_num = [] # 인접노드 번호

v: list[Node] = []
v.append(None)
for _ in range(N):
    lst = list(map(int,input().split()))
    node = Node(lst[0]) # 가중치
    node.adjs_num = lst[2:]
    v.append(node)
dp[1] = v[1].weight # 1번 노드는 선행작업이 없으니 자기 자신만 수행한 값이 정답
visit[1] = True # 이 문제에서는 시작점을 1번으로 줬음

def dfs(node_num: int):
    if visit[node_num]:
        return dp[node_num]
    visit[node_num] = True
    adjs_num = v[node_num].adjs_num
    w = v[node_num].weight
    
    # 인접노드들 중에 가장 오래걸리는거 찾기
    # 왜 정답은 최소시간 찾기인데 최대값을 찾냐면,
    # 결국 내가 이 코드에서 정의한 인접노드는 "선행작업"임.
    # 선행작업이 전부 완료되지 못하면 어차피 현재 작업을 완료하지 못하기 때문
    # 따라서 선행작업이 여러개인 것중에서 가장 오래걸리는걸 하고 그 다음 바로 현재 작업 시행한다는 원리
    # 선행작업 중에 가장 오래걸리는 시간에다가 현재 걸리는 시간을 더해야함
    
    # 주의 : max_val은 무조건 0이여야하고, 음수로 설정하면 안됨
	  #      음수로 설정시 인접노드가 없어서 아래 for문 안도는 경우 음수값이 정답이됨
    max_val = 0 
    
    for adj in adjs_num:
        max_val = max(max_val,dfs(adj))
    dp[node_num] = max_val + w # w를 더하는 과정은 곧 현재 작업을 하는데 걸리는 시간 계산한다는 것
    return dp[node_num]

# 여기가 또 
for i in range(len(dp)-1,0,-1):
    dfs(i)

# dp[0]은 빈공간(편의를 위해) / inf값이 들어있는건 거르는 용도
print(max(dp[1:]))



