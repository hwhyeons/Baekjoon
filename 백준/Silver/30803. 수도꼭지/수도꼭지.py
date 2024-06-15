import sys
input = sys.stdin.readline
N = map(int,input().split())
v = list(map(lambda x:[int(x),True],input().split()))
Q = int(input().strip())
before = sum([x[0] for x in v if x[1]])
print(before)
for _ in range(Q):
    tp = tuple(map(int,input().split()))
    if tp[0] == 1:
        before_v = v[tp[1]-1][0]
        new_value = tp[2]
        v[tp[1] - 1][0] = new_value
        if not v[tp[1]-1][1]: # 닫혀있는 경우
            print(before)
        else:
            new_sum = before - before_v + new_value
            print(new_sum)
            before = new_sum
    elif tp[0] == 2:
        v[tp[1]-1][1] = not v[tp[1]-1][1]
        if v[tp[1]-1][1]: # 바꾼게 여는 방향인 경우
            new_value = before + v[tp[1]-1][0]
        else: # 바꾼게 닫는방향인 ㅕㄱㅇ우
            new_value = before - v[tp[1]-1][0]
        print(new_value)
        before = new_value






