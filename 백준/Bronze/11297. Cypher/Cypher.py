
def cal(c,val):
    ans = ord(c)-1-val
    if ans < ord('a'):
        ans = ord('z') - (ord('a')-ans) + 1
    return chr(ans)

while True:
    a,b,c = map(int,input().split())
    if not a and not b and not c:
        break
    line = input()
    v = (a+b+c)%25
    new_line = ''
    for ch in line:
        if ord(ch) < ord('a') or ord(ch) > ord('z'):
            new_line+=ch
            continue
        else:
            new_line+=cal(ch,v)
    print(new_line)