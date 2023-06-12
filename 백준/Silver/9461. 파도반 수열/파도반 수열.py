import functools

@functools.lru_cache
def f(n):
    if n <= 3:
        return 1
    return f(n - 2) + f(n - 3)

tcnt = int(input())
for tc in range(1, tcnt + 1):
    n = int(input())
    print(f(n))
