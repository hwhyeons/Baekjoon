import sys

def f(n):
    ans = 1
    for i in range(1,n+1):
        ans *= i
    return ans

t = int(sys.stdin.readline().split()[0])
for i in range(t):
    s = sys.stdin.readline().split()
    r = int(s[0])
    n = int(s[1])
    print(f(n)//(f(r)*f(n-r)))

    
    
    
