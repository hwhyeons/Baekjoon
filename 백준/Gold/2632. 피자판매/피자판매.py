


import sys
from itertools import accumulate


def make_dict(acc_ar):
    acc_dict = dict()
    first_val = acc_ar[0] # 맨 앞
    all_sum = acc_ar[-1] # 전체 합 (맨 뒤)
    acc_dict[first_val] = 1
    acc_dict[all_sum] = 1
    for i in range(len(acc_ar)):
        for j in range(i+1,len(acc_ar)):
            g = acc_ar[j]-acc_ar[i] # gap
            if not g in acc_dict:
                acc_dict[g] = 1
            else:
                acc_dict[g] += 1

            g2 = all_sum-g
            if i == 0 and j == len(acc_ar)-1: # 맨앞과 맨뒤
                continue
            else:
                if not g2 in acc_dict:
                    acc_dict[g2] = 1
                else:
                    acc_dict[g2] += 1
    return acc_dict


# sys.setrecursionlimit(10**6)
# 메모리 초과 -> pypy 대신 python / recursionlimit 제한 하기
input = sys.stdin.readline
want = int(input())
m,n = map(int,input().split())

v1 = []
v2 = []
ans_set = set()
for i in range(m):
    v1.append(int(input().rstrip("\n")))

for i in range(n):
    v2.append(int(input().rstrip("\n")))

acc1 = list(accumulate(v1))
acc2 = list(accumulate(v2))

acc_dict1 = make_dict(acc1)
acc_dict2 = make_dict(acc2)

answer = 0
for k in acc_dict1:
    need_gap = want - k
    if need_gap < 0:
        continue
    elif need_gap == 0:
        answer += acc_dict1[k] # value : 개수
    elif need_gap > 0:
        if need_gap in acc_dict2:
            answer += (acc_dict1[k] * acc_dict2[need_gap])


# acc2 단독으로 가능한 경우
for k in acc_dict2:
    if k == want:
        answer += acc_dict2[k]
print(answer)

# cnt = 0
#
# s1 = 0
# e1 = 1
# while True:
#     sum1 = acc1[e1]-acc1[s1]
#     gap:int = want - sum1
#     if gap < 0:
#         s1+=1
#     elif gap ==0: # 혼자서 되는 경우
#         cnt+=1
#     else: # 이제 gap만큼을 만족하는 값을 acc2에서 찾아야함
#
#     # 같을 경우 증가
#     if e1 == s1:
#         e1+=1
#         s1+=1

