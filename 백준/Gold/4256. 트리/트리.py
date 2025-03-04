from collections import deque
import sys
sys.setrecursionlimit(1000000)
T_CNT = int(input())

class Node:
    def __init__(self):
        self.parent = None
        self.value = None
        self.lchild = None
        self.rchild = None


def add_child_node(node,check_set, child_value):
    # l_child_idx = parent_idx*2
    # r_child_idx = parent_idx*2 + 1
    if node.lchild is None:
        node.lchild = Node()
        node.lchild.value = child_value
        node.lchild.parent = node
        check_set.add(child_value)
        return node.lchild
    if node.rchild is None:
        node.rchild = Node()
        node.rchild.value = child_value
        node.rchild.parent = node
        check_set.add(child_value)
        return node.rchild
    # if tree[l_child_idx] is None:
    #     tree[l_child_idx] = child_value
    #     check_set.add(child_value)
    #     return l_child_idx
    # elif tree[r_child_idx] is None:
    #     tree[r_child_idx] = child_value
    #     check_set.add(child_value)
    #     return r_child_idx
    raise "err"

def find_parent_node(node, value):
    # 특정값을_가진_부모찾기
    # 자기위치 그대로면 리턴
    # cur_idx : 출발점 인덱스
    # if tree[cur_idx] == value:
    if node.value == value:
        return node
    else:
        # assert cur_idx != 1 # 루트노드까지 도달했는데도 못찾은 경우
        assert node.parent is not None
        return find_parent_node(node.parent,value)
        # return find_parent_idx(tree,value,cur_idx//2)

def init_tree(check_set, pres, ins, node):
    # pres : deque[int]
    # ins : deque[int]
    # tree : list[None | int] -> None이면 아직 빈공간
    # idx : 현재 인덱스

    # 전부 다 소모한 경우
    if not pres and not ins:
        return

    # 중위순회 남아있는 경우 -> 중위순회의 front값이 나올 때 까지 자식확장?
    if ins:
        top_ins = ins[0]
        if top_ins in check_set:
            parent_node = find_parent_node(node,top_ins)
            # 해당 부모로 이동 후에 다시 시작
            # 중위에서 제거 필요
            ins.popleft()
            init_tree(check_set,pres,ins,parent_node)
            return

        top_pres = pres[0]
        if top_ins == top_pres:
            # 같은 경우? pres랑 ins에서 둘다 제거 후 진행
            pres.popleft()
            ins.popleft()
            # add_child(tree,check_set,idx,top_ins) # 현재위치에 자식은 추가하고 현재위치에서 다시..?
            child_node = add_child_node(node,check_set,top_ins) # 현재위치에 자식은 추가하고 자식으로 이동
            init_tree(check_set, pres, ins, child_node) # 똑같은 위치에서 진행
        else:
            # 다르면 현재? 자식으로 추가
            pres.popleft()
            child_node = add_child_node(node,check_set,top_pres) #
            init_tree(check_set,pres,ins,child_node)
        return

    # 전위순회리스트는_있는데_중위순회는다쓴경우?
    raise "no"



def print_answer(node):
    # 후위순회
    if node.lchild is not None:
        print_answer(node.lchild)
    if node.rchild is not None:
        print_answer(node.rchild)
    print(node.value, end=' ')
    return



for _ in range(T_CNT):
    N = int(input())
    pres = deque(map(int, input().split()))
    ins = deque(map(int, input().split()))
    check_set = set() # 해당 값이 "할당"이 되었는지 (단순 방문X)
    # tree = [None]*N*N # 1000N의 크기로 이진트리 생성
    # tree[1] = pres[0] # 전위순회의 첫번째 값이 곧 리프노드
    root_node = Node()
    root_node.value = pres[0]
     # 맨 앞꺼 추가했으니 삭제
    check_set.add(pres.popleft())
    init_tree(check_set,pres,ins,root_node) # 루트노드부터 시작
    print_answer(root_node)
    print()


