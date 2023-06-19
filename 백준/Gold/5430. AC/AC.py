
tcnt = int(input())
while tcnt>0:
    tcnt-=1

    cmd = input()
    input()
    r = False
    left = 0
    right = 0
    for c in cmd:
        if c == "R":
            r = not r
        elif c == "D":
            if r:
                right+=1
            else:
                left+=1

    v = input().strip("[").strip("]").split(",")
    if left+right > len(v):
        print("error")
    elif left+right >= 1 and v[0] == '':
        print("error")
    else:
        v = v[left:len(v)-right]
        if r:
            v = list(reversed(v))
        print("["+",".join(v)+"]")




