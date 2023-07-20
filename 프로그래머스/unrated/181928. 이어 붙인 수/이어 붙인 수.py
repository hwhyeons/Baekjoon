def solution(num_list):
    return int("".join(map(str,filter(lambda x : x%2==0,num_list))))+int("".join(map(str,filter(lambda x : x%2,num_list))))

