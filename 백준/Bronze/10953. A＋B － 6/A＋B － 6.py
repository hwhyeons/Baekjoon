n = int(input())
gen = (sum(map(int, input().split(","))) for _ in range(n))
print(*gen)