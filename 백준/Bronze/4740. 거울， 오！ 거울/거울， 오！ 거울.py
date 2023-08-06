while True:
    s = input()
    if s=="***": break
    print(*reversed(s),sep="")