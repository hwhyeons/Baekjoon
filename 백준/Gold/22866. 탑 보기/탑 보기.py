N = int(input())
v = list(map(int,input().split()))

class Node:
    def __init__(self,node_num: int, height: int):
        self.node_num = node_num
        self.height = height

    def __repr__(self):
        return f'{self.node_num} / {self.height}'

def func(is_left: bool):
    can_see = [0] * (N + 1)
    close = [100000000] * (N + 1) # 왼쪽으로 볼 수 있는 가장 가까운 것

    # 왼쪽부터 계산
    stk:list[Node] = []
    rng = range(len(v)) if is_left else reversed(range(len(v)))
    for idx in rng:
        node_num = idx+1 # 번호는 1번부터 시작
        cur_height = v[idx]
        # 스택에 없으면 추가
        if not stk:
            stk.append(Node(node_num,cur_height))
            continue
        # 스택의 top이 자신보다 큰 경우 -> 스택에 이어 붙이기
        if stk[-1].height > cur_height:
            stk.append(Node(node_num,cur_height))
            continue
        # 스택의 top이 자신보다 작거나 같은 경우
        # 교체 해야함 -> 이때 최대한 다 뺴야함
        # 이때 정답 갱신 필요
        # 예시) 7 6 5 1에서 7이 들어온 경우
        while stk:
            if not stk:
                break
            if stk[-1].height <= cur_height:
                can_see[stk[-1].node_num] = len(stk) - 1
                if len(stk) >= 2:
                    close[stk[-1].node_num] = stk[-2].node_num
                stk.pop()
                continue
            # 스택 탑이 자신보다 큰 경우
            break
        stk.append(Node(node_num,cur_height))
        continue

    # 이제 스택에 남은것들을 전부 처리해야함
    while stk:
        can_see[stk[-1].node_num] = len(stk) - 1
        if len(stk) >= 2:
            close[stk[-1].node_num] = stk[-2].node_num
        stk.pop()

    return close,can_see

left_answer_close,left_answer_cansee = func(True)
right_answer_close,right_answer_cansee = func(False)

for num in range(1,len(left_answer_cansee)):
    # 둘다 정답이 없는 경우
    if left_answer_cansee[num] == 0 and right_answer_cansee[num] ==0:
        print(0)
    elif left_answer_cansee[num] > 0 and right_answer_cansee[num] ==0:
        print(left_answer_cansee[num],left_answer_close[num])
    elif left_answer_cansee[num] == 0 and right_answer_cansee[num] > 0:
        print(right_answer_cansee[num],right_answer_close[num])
    else:
        # 둘다 정답이 있는 경우
        ans_cnt = left_answer_cansee[num] + right_answer_cansee[num]
        left_dist = num-left_answer_close[num]
        right_dist = right_answer_close[num]-num
        assert left_dist > 0 and right_dist > 0
        # 왼쪽으로 (같은 경우도 마찬가지)
        if left_dist <= right_dist:
            print(ans_cnt,left_answer_close[num])
        else:
            print(ans_cnt,right_answer_close[num])





