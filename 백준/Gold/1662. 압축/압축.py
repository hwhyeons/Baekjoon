
line = input()

def dfs(s: str) -> tuple[int,int]:
    length = 0
    before_number = 0
    idx = 0
    while idx < len(s):
        c = s[idx]
        if c == '(':
            length-=1
            d = dfs(s[idx+1:])
            length+=before_number*d[0]
            idx+=d[1]+2
        elif c == ')':
            return length,idx
        else:
            before_number = int(c)
            length += 1
            idx+=1
    return length,len(s)-1
print(dfs(line)[0])