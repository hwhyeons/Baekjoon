import functools
import sys

sys.setrecursionlimit(10**6)

dx, dy = (1, -1, 0, 0), (0, 0, 1, -1)
visit = []
all = []


# @functools.cache
def dfs(y, x):
    global all, n, m, dp,visit
    if visit[y][x]:
        return dp[(y,x)]
    visit[y][x] = True
    ans = 0
    for i, j in zip(dx, dy):
        ny = y + j
        nx = x + i
        if ny < 0 or nx < 0 or ny >= n or nx >= m:
            continue
        elif all[ny][nx] <= all[y][x]:
            continue
        elif ny == 0 and nx == 0:
            ans += 1
            continue
        ans += dfs(ny, nx)
    dp[(y,x)] = ans
    return ans


if __name__ == '__main__':
    dp = dict()
    n, m = map(int, input().split())
    visit = [[False for _ in range(m)] for _ in range(n)]
    for i in range(n):
        all.append(list(map(int,input().split())))
    print(dfs(n-1, m-1))
    print("",end="")