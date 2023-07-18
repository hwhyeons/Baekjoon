def solution(a, b, c):
    l = len(set([a,b,c]))
    return (a+b+c)*(a*a+b*b+c*c)*(a*a*a+b*b*b+c*c*c) if l==1 else (a+b+c)*(a*a+b*b+c*c) if l == 2 else a+b+c
 