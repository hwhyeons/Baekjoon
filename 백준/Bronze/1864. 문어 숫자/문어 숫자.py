d = {"-":0, "\\":1, "(":2, "@":3, "?":4, ">":5, "&":6, "%":7, "/":-1}
while True:
    s = input()
    if s == '#': break
    ans = 0
    for i in range(len(s)):
        num = d[s[i]]
        num = num * (8**(len(s)-i-1))
        ans += num
    print(ans)
