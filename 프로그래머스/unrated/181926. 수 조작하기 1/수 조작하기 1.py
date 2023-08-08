import collections as c
def solution(n, control):
    a,d,s,w=c.Counter(sorted(control)).values()
    return n+w-s+10*(d-a)