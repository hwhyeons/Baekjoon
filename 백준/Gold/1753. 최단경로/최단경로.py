from collections import defaultdict
from queue import PriorityQueue
import math


class Edge:
    def __init__(self, index, dist):
        self.index = index
        self.dist = dist

    def __lt__(self, other):
        return self.dist < other.dist


fd = open(0)
input = fd.readline

edges = dict()

V,E = map(int,fd.readline().split())
K = int(fd.readline())
for _ in range(E):
    u,v,w = map(int,input().split())
    if u not in edges:
        edges[u] = dict()
    if v in edges[u]:
        edges[u][v] = min(w,edges[u][v])
    else:
        edges[u][v] = w

min_dist = dict()
min_dist[K] = 0


pq = PriorityQueue()
pq.put_nowait(Edge(K,0))
while not pq.empty():
    edge: Edge = pq.get_nowait()
    node_number = edge.index
    edge_dist = edge.dist
    if node_number not in edges:  # 인접 노드가 없는 경우
        continue
    adjust_nodes = edges[node_number].items()
    for adj_node_number, weight in adjust_nodes:
        # 인접한 경우가 없는경우 -> pq에 무조건 추가
        if adj_node_number not in min_dist or edge_dist+weight < min_dist[adj_node_number]:
            pq.put_nowait(Edge(adj_node_number,edge_dist+weight))
            min_dist[adj_node_number] = edge_dist+weight


for idx in range(1,V+1):
    if idx == K:
        print(0)
    elif idx not in min_dist:
        print("INF")
    else:
        print(min_dist[idx])




