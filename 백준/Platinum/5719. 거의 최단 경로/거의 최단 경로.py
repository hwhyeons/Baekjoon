import math
import sys
import heapq


def dijkstra(N,M,S,D,d,before_dir,second_mode: bool, remove_set: set[tuple[int,int]]):
    if second_mode:
        assert remove_set is not None
    else:
        assert not remove_set
    min_dist = [math.inf for _ in range(N)]
    min_dist[S] = 0
    min_dist_visit = [False for _ in range(N)]
    min_dist_visit[S] = True

    heap = [(0,S)]

    while heap:
        cur_node = heapq.heappop(heap)
        cur_node_idx = cur_node[1]
        cur_node_weight = cur_node[0]
        # min_dist_visit[cur_node_idx] = True
        for friend in d[cur_node_idx]:
            # 인접 노드에서 갱신할지 말지 결정
            friend_idx = friend[0]
            # 만약 두번째 다익스트라인 경우 -> (시작점->끝점)이 존재하는 경우
            if second_mode and (cur_node_idx,friend_idx) in remove_set:
                continue
            friend_w = friend[1]
            # 이미 방문한 인접 노드
            if min_dist_visit[friend_idx]:
                continue
            if min_dist[cur_node_idx] + friend_w <= min_dist[friend_idx]:
                # 같은 경우에는 이전 경로만 넣고, 작은 경우에만 힙큐에 추가;
                if min_dist[cur_node_idx] + friend_w < min_dist[friend_idx]:
                    # 힙에 추가
                    heapq.heappush(heap,(min_dist[cur_node_idx] + friend_w,friend_idx))
                    min_dist[friend_idx] = min_dist[cur_node_idx] + friend_w
                    # min_dist_visit[friend_idx] = True  # !! 이 위치에서 해야 초과 X
                    # 이전경로 제거 후 추가
                    before_dir[friend_idx] = []
                    before_dir[friend_idx].append(cur_node_idx)
                elif min_dist[cur_node_idx] + friend_w == min_dist[friend_idx]:
                    # 이전경로 이어서 추가
                    if friend_idx not in before_dir:
                        before_dir[friend_idx] = []
                    before_dir[friend_idx].append(cur_node_idx)
                else:
                    raise Exception("잘못된 경우")
    if second_mode:
        if min_dist[D] == math.inf:
            print(-1)
        else:
            print(min_dist[D])



while True:
    N,M = map(int, sys.stdin.readline().split())
    d = [list() for _ in range(N)]
    before_dir = dict() # 이전 방향

    if N==0 and M==0:
        break
    S, D = map(int, sys.stdin.readline().split())
    for _ in range(M):
        U,V,P = map(int, sys.stdin.readline().split())
        d[U].append((V,P))

    dijkstra(N,M,S,D,d,before_dir,second_mode=False,remove_set=None)

    # 이제 최단 경로에 해당하는 모든 간선들은 제외하고 다시 다익스트라
    remove_edge_set = set() # Tuple[(시작노드,끝노드)]
    # 시작점과 끝점은 넣으면 안됨
    # 끝점부터 시작점까지 역추적 해서 set에 추가
    from collections import deque
    dq = deque()
    dq.append(D)
    # 처음에 bfs_set을 노드 번호 하나로 했더니 일부 문제에서 오답
    # bfs_set도 시작 경로와 도착경로로 따져야함
    bfs_set = set()
    while dq:
        cur_re = dq.popleft()  # 끝점부터 추적
        # 시작점은 더이상 역추적이 안됨
        if cur_re == S:
            continue
        # assert type(before_dir[cur_re]) == list 아예 노드가 끊어진 경우에는 여기서 예외
        if cur_re not in before_dir:
            continue
        for before_idx in before_dir[cur_re]:
            if (before_idx,cur_re) in bfs_set:
                continue
            remove_edge_set.add((before_idx,cur_re))
            bfs_set.add((before_idx,cur_re))
            dq.append(before_idx)
    # print("최소 경로로 거쳐간 간선  : ",remove_edge_set)

    # 다시 한번 다익스트라 알고리즘
    before_dir = dict() # 이전 방향
    dijkstra(N,M,S,D,d,before_dir,second_mode=True,remove_set=remove_edge_set)


