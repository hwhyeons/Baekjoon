from __future__ import annotations
from itertools import combinations
import heapq

kill_cnt = 0 # global
class Enemy:
    dead_dict_by_kill: dict[int,int] = dict() # key : id / value : turn
    # dead_set_self: set[int] = set()
    # current_location: dict[int,tuple[int,int]] = dict()
    def __init__(self,id: int, r: int, c: int, p_r: int, p_c: int):
        self.id = id # 세 궁수 모두 이 id를 공유
        self.r = r
        self.c = c
        self.p_r = p_r # 궁수
        self.p_c = p_c # 궁수

    # def __str__(self):
    #     return f"id : {self.id} / r,c : {(self.r,self.c)} / 궁수 : {(self.p_r,self.p_c)}"

    def __lt__(self, other: Enemy):
        # 1. abs로 비교
        dist_me = self.get_dist()
        dist_other = other.get_dist()
        if other.p_r != self.p_r or self.p_c != other.p_c:
            raise Exception("Not Same")

        if dist_me != dist_other:
            return dist_me < dist_other

        # 같은경우 더 왼쪽에 있는게 승자
        return self.c < other.c

    def get_dist(self) -> int:
        return abs(self.r-self.p_r) + abs(self.c - self.p_c)

    # @staticmethod
    # def check_dead_by_self(id :int):
    #     if id in Enemy.dead_set_self:
    #         return True
    #     return False

    @staticmethod
    def kill_id(id: int, turn: int) -> bool: # retry가 필요하면 True
        global kill_cnt
        if id not in Enemy.dead_dict_by_kill:
            kill_cnt += 1
            Enemy.dead_dict_by_kill[id] = turn
            return False
        # 존재하는 경우 -> 재시도 여부 결정
        if Enemy.dead_dict_by_kill[id] == turn: # 현재 턴에 된 경우 -> 재시도 X
            return False
        return True


    # @staticmethod
    # def kill_self(id :int):
    #     # 이거는 이동에 의해 없어진 경우
    #     # if id not in Enemy.dead_set and id not in Enemy.dead_set_self:
    #     #     Enemy.dead_set.add(id)
    #     Enemy.dead_set_self.add(id)



N,M,D = map(int,input().split())
v = []

cur_monster_id = 1
base_monster_list: list[tuple[int,int,int]] = [] # r,c,id
for row in range(N):
    lst = list(map(int,input().split()))
    for col in range(M):
        if lst[col] == 1:
            lst[col] = cur_monster_id
            base_monster_list.append((row,col,cur_monster_id))
            cur_monster_id+=1
    v.append(lst)

def attack_all(heap1: list[Enemy],heap2: list[Enemy],heap3: list[Enemy],attack_turn: int) -> None:
    # 1번 공격자부터 시작
    lst = [heap1,heap2,heap3]
    for h in lst:
        while h:
            top: Enemy = heapq.heappop(h)
            # 다른 대상에 의해 죽은 경우 체크
            if top.r >= top.p_r:
                continue
            # 거리가 더 긴 경우 : 다시 넣고 break
            dist = top.get_dist()
            if dist > D:
                heapq.heappush(h,top)
                break
            retry= Enemy.kill_id(top.id,attack_turn)
            if retry: # 재시도 시그널
                continue
            # print(f"turn : {attack_turn}/ kill : {top.id} / r,c : {(top.r,top.c)} / 궁수 : {(top.p_r,top.p_c)}")
            break

def move_all(heap1: list[Enemy],heap2: list[Enemy],heap3: list[Enemy]):
    for h in [heap1,heap2,heap3]:
        for enemy in h:
            enemy.r+=1
        heapq.heapify(h)
    

max_kill_cnt = 0
for tp in combinations(range(M),3):
    p1_c,p2_c,p3_c = tp # 뽑힌 세 궁수의 column
    heap1: list[Enemy] = []
    heap2: list[Enemy] = []
    heap3: list[Enemy] = []
    Enemy.dead_dict_by_kill.clear()
    kill_cnt = 0 # clear kill_cnt
    for tp in base_monster_list:
        r,c,id = tp
        heapq.heappush(heap1,Enemy(id,r,c,N,p1_c))
    for tp in base_monster_list:
        r,c,id = tp
        heapq.heappush(heap2,Enemy(id,r,c,N,p2_c))
    for tp in base_monster_list:
        r,c,id = tp
        heapq.heappush(heap3,Enemy(id,r,c,N,p3_c))
    attack_turn = 1
    while heap1 or heap2 or heap3:
        attack_all(heap1,heap2,heap3,attack_turn)
        move_all(heap1,heap2,heap3)
        attack_turn+=1
    # print(f"이번에 : {p1_c},{p2_c},{p3_c} / {kill_cnt}")
    max_kill_cnt = max(max_kill_cnt,kill_cnt)
print(max_kill_cnt)