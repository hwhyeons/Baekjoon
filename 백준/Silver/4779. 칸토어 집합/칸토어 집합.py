
import sys
all_line: list[str] = sys.stdin.readlines()

def f(v: list[str], s: int, length: int):
    # ex) s=0 / length=9
    cons = length//3
    if length == 1:
        return
    split_start = s + cons # ex) s=0 / split_start=3
    split_end = s + 2*cons # ex) s=0 / split_end=6
    for i in range(split_start, split_end):
        v[i] = ' '
    f(v,s,cons)
    f(v,split_end,cons)
    
    
    

for line in all_line:
    num: int = int(line[:-1]) # 엔터 있으므로 주의
    start_hypen: str = '-'*(3**num)
    v = list(start_hypen)
    f(v,0,len(v))
    print(''.join(v))
