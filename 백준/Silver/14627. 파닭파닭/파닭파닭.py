S,C = map(int,input().split())
v: list[int] = []
for _ in range(S):
    v.append(int(input()))

if len(v) == 1:
    print(0)
    exit(0)

startValue = 0
endValue = sum(v)//C
all_sum = sum(v)

max_one_length = 0
max_acc = 0
while startValue <= endValue:
    mValue: int = (startValue+endValue)//2
    acc = 0
    acc_cnt = 0
    for element in v:
        # acc += (element - element%mValue) # element//mValue
        cnt = element // mValue
        acc += cnt * mValue
        acc_cnt += cnt

    if acc_cnt < C:
        endValue = mValue-1
    else:
    # elif acc >= max_acc:
        startValue = mValue+1
        max_one_length = mValue
    max_acc = max(acc,max_acc)

answer = 0
acc_real_cnt = 0
for k in v:
    left = k%max_one_length
    if acc_real_cnt + k//max_one_length <= C:
        answer += left
        acc_real_cnt += k//max_one_length
    else:
        answer += k - (C-acc_real_cnt)*max_one_length
        break

print(answer)