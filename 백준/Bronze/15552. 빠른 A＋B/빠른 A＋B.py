import sys
# n = int(sys.stdin.readline().strip())
# for _ in range(n):
#     a, b = map(int, sys.stdin.readline().split())
#     sys.stdout.write(str(a + b) + " ")

n = int(sys.stdin.readline().strip())
[sys.stdout.write(str(sum(map(int, sys.stdin.readline().strip().split())))+" ") for _ in range(n)]