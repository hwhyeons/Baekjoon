line = input()

# d: dict[tuple[int,int],int] = dict()
d: dict[str,int] = dict()

def dfs(s: str):
    if s in d:
        return d[s]
    if len(s) == 1:
        return 1
    left_remove_str = s[1:]
    right_remove_str = s[:-1]
    left_remove_answer = dfs(left_remove_str)
    if left_remove_str == right_remove_str:
        right_remove_answer = 0
    else:
        right_remove_answer = dfs(right_remove_str)
    d[s] = left_remove_answer+right_remove_answer
    return left_remove_answer+right_remove_answer





answer = dfs(line)
print(answer)