def solution(a, d, included):
    return sum(v*(a+i*d)for i,v in enumerate(included))
