# import sys
# n = int(sys.stdin.readline().strip())
# gen =[sum(map(int, sys.stdin.readline().split())) for _ in range(n)]
# print(*gen)
# vs
import sys
n = int(sys.stdin.readline().strip())
gen = (sum(map(int, sys.stdin.readline().split())) for _ in range(n))
print(*gen)