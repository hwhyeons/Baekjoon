from collections import defaultdict
import sys
input = sys.stdin.readline
n = int(input().rstrip("\n"))

d = defaultdict(lambda :[0,False])

for _ in range(n):
    check_num, user_id, result, mem, time, lang, code_len = input().split()
    if user_id == "megalusion":
        continue
    if result == "4":
        d[user_id][1] = True
    else:
        if d[user_id][1]: # 한번이라도 맞은 적이 있는 경우
            continue
        else:
            d[user_id][0] += 1

if len(d) == 0:
    print("0")
else:
    only_correct = list(map(lambda lst: lst[0], filter(lambda lst: lst[1] == True, d.values())))
    if not only_correct:
        print("0")
    else:
        ratio = len(only_correct)/(len(only_correct)+(sum(only_correct)))*100
        print(str(ratio))
