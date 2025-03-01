from typing import *
dp = [[] for _ in range(9)]
global_N = 0 # 예제1 : 5
global_number = 0 # 예제1 : 12
ans = 1000000000

def f(n: int) -> List[int]:
    global global_N,ans,global_number
    if n == 0:
        raise "error"
    if dp[n]:
        return dp[n]
    ans_list = []
    # 자기자신만 사용 
    only_mine = int(str(global_N)*n) # ex : 5555
    # print("only_mine",only_mine)
    ans_list.append(only_mine) 
    for i in range(1,n):
        a = i
        b = n-i
        first_list: List[int] = f(a)
        second_list: List[int] = f(b)
        for fisrt in first_list:
            for s in second_list:
                ans_list.extend(cal(fisrt,s))
    dp[n] = ans_list
    # for ans_tmp in ans_list:
    #     if ans_tmp == global_number:
    #         ans = min(ans,n) # 가장 적게 사용하기
    return ans_list
    
def cal(n1: int, n2: int) -> List[int]:
    rt_list = []
    rt_list.append(n1+n2)
    rt_list.append(n1*n2)
    if n2 !=0:
        rt_list.append(n1//n2)
    rt_list.append(n1-n2)
    return rt_list

def solution(N: int, number):
    global global_N,global_number,ans
    global_N = N
    global_number = number
    dp[1].append(N) # 숫자 한개 사용 -> 5
    dp[2].append(N*10+N) # 숫자 두개 사용 -> 55
    dp[2].extend(cal(N,N)) # 숫자 두개 사용 -> 5+5 ... 
    f(8)
    # 정답 찾기
    for idx_num,one_dimand_list in enumerate(dp):
        for one_number in one_dimand_list:
            if one_number == number:
                ans = min(ans,idx_num)
    
    # print(dp)
    if ans == 1000000000 or ans > 8:
        return -1
    return ans