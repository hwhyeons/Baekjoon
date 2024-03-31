import math

N,M = map(int,input().split())
colors: list[int] = []
for _ in range(M):
    colors.append(int(input()))

s = 1
e = max(colors)

min_answer = math.inf
while s <= e:
    m = (s+e)//2
    ok = 0 # 미리 예측 최대 개수로 배정받은 사람들
    category_count_left = 0
    tf_continue = False
    for color_count in colors:
        tmp =  color_count//m
        tmp_left = color_count%m
        # 초과 하면 더 늘려야함
        if ok + tmp > N:
            s = m + 1
            tf_continue = True
            break
        else:
            ok += tmp
            if tmp_left != 0:
                category_count_left += 1 # ex) 7개인데 4개씩 주면 3개남음 -> 남았으니 나중에 배분 예정
    if tf_continue:
        continue
    left_people = N - ok # 최대 개수 배정말고 남는거 받아야 하는 사람들

    # 불가능한 경우 : 남는 색깔의 종류가 5개인데 사람 수는 3명이면 남는걸 재분배 해야됨
    if category_count_left > left_people:
        s = m + 1
        continue
    min_answer = min(m,min_answer)
    e = m -1

print(min_answer)