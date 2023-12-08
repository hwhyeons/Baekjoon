n = int(input())
[print(sum(map(int, input().split(",")))) for _ in range(n)]