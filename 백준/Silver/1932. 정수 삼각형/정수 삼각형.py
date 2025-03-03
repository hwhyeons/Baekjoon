n = int(input())
v = []
for _ in range(n):
    v.append(list(map(int, input().split())))

d = dict() # key : tuple(depth, idx)

def dp(depth: int, idx: int):
    global v,d
    if (depth, idx) in d:
        return d[(depth,idx)]
    # 맨 마지막 깊이
    if depth == len(v) -1:
        return v[depth][idx]
    left_child_idx = idx
    right_child_idx = idx+1
    left_dp = dp(depth+1,left_child_idx)
    right_dp = dp(depth+1,right_child_idx)
    d[(depth,idx)] = max(left_dp,right_dp) + v[depth][idx]
    return d[(depth,idx)]


print(dp(0,0))


