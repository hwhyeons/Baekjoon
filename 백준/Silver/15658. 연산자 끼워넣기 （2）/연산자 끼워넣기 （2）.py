import math

N = int(input())
v = list(map(int, input().split()))
op_list_tmp = list(map(int, input().split()))
op_dict = {'+':op_list_tmp[0],'-':op_list_tmp[1],'*':op_list_tmp[2],'/':op_list_tmp[3]}
min_ans = math.inf
max_ans = -math.inf

def dfs(before_val: int, index: int):
    global min_ans,max_ans,op_dict
    if index >= N: # 숫자 인덱스
        min_ans = min(min_ans, before_val)
        max_ans = max(max_ans, before_val)
        return
    for key in op_dict:
        cnt = op_dict[key]
        if cnt == 0:
            continue
        op_dict[key] -=1
        if key == '+':
            new_val = before_val+v[index]
        elif key == '-':
            new_val = before_val-v[index]
        elif key == '*':
            new_val = before_val*v[index]
        elif key == '/':
            new_val = int(before_val / v[index])
            # if before_val < 0 and v[index] > 0: # 음수를 양수로 나누는 경우
            #     new_val = -((-before_val)//v[index])
            # else:
            #     new_val = before_val//v[index]
        else:
            raise Exception("err")

        dfs(new_val,index+1)
        op_dict[key] +=1
dfs(v[0],1)

print(max_ans)
print(min_ans)