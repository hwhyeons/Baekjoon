def f(s):return f(l)+(f(r) if l!=(r:=s[:-1]) else 0) if (l:=s[1:]) else 1
print(f(input()))