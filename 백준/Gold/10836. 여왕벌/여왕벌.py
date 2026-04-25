
M,N = map(int,input().split())
acc = [] # 누적배열
for _ in range(N):
    grow_0,grow_1,grow_2 = map(int,input().split())
    acc.append([grow_0,grow_0+grow_1,grow_0+grow_1+grow_2])


# cnt_arr 만들기
cnt_arr = [0]*(2*M-1)
for lst in acc:
    g0,g1,g2 = lst
    if g0 < len(cnt_arr):
        cnt_arr[g0] += 1
    if g1 < len(cnt_arr):
        cnt_arr[g1] += 1

# print(cnt_arr)real_acc

# real_acc 만들기
real_acc = cnt_arr.copy()
for idx in range(1,len(real_acc)):
    real_acc[idx] = real_acc[idx-1] + cnt_arr[idx]

# 실제 최종 grow배열
# end_grow_arr
end_grow_arr = real_acc.copy()
for idx in range(len(end_grow_arr)):
    end_grow_arr[idx] += 1

# print(end_grow_arr)


# 이제 row, col에 따라 출력만
for r in range(M):
    for c in range(M):
        if r == 0 and c==0:
            print(end_grow_arr[M-1],end=' ')
        elif r == 0:
            print(end_grow_arr[M+c-1],end=' ')
        elif c == 0:
            print(end_grow_arr[M-r-1],end=' ')
        else:
            # 일반 숫자
            print(end_grow_arr[M+c-1],end=' ')
    print() # 행 변경



