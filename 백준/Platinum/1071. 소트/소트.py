import sys
sys.setrecursionlimit(100000)
import heapq
N = int(input())
v = list(map(int, input().split()))
heapq.heapify(v)
answer = []

def recover_banned_number(banned_dict: dict):
    global v
    for k,val in banned_dict.items():
        for _ in range(val):
            heapq.heappush(v,k)


min_idx = 0
def dfs() -> bool:
    # s_idx : 시작 인덱스
    global answer,v,min_idx
    if N == len(answer):
        print(*answer)
        exit(0)
    banned_number_dict = dict() # 금지 숫자 / 금지 수
    while True:
        # 빈공간 -> 해당 번호로 진행 불가능
        if not v:
            recover_banned_number(banned_number_dict)
            return False
        cur_number = heapq.heappop(v)
        if cur_number in banned_number_dict:
            banned_number_dict[cur_number] += 1
            continue
        # 값 차이가 1 -> 금수로 추가
        if len(answer) > 0 and cur_number == answer[-1]+1:
            assert cur_number not in banned_number_dict
            banned_number_dict[cur_number] = 1
            continue

        # 일단 문제가 없는 경우 -> 추가
        answer.append(cur_number)
        # 다음 dfs에서는 지금 깊이에서 금지 당한 숫자가 금지일 보장은 전혀 없으니 풀고 가야함
        recover_banned_number(banned_number_dict)
        dfs()
        # 여기에 도착 -> 현재 숫자로는 다음에 대응이 안됨(ex : 여기서 5를쓰고 다음에 5를썼더니 남은게 6이라 불가능)
        # assert cur_number not in banned_number_dict
        banned_number_dict[cur_number] = 1
        answer.pop()
        continue
    recover_banned_number(banned_number_dict)
    return False
dfs()
