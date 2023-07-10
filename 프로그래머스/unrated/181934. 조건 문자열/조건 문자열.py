def solution(ineq, eq, n, m):
    return 1 if eval(f'n{ineq}{"="if eq =="=" else ""}m') else 0
