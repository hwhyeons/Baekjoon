import functools
import sys
sys.setrecursionlimit(10**8)

@functools.cache
def f(n):
    if n < 2:
        return n
    return f(n - 1) + f(n - 2)


print(f(int(input())))
