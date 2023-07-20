def solution(num_list):
    from functools import reduce
    return 1 if reduce(lambda x1,x2 : x1*x2,num_list) < sum(num_list)**2 else 0
    