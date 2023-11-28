all_list = [*open(0)]
n = int(all_list[0].split()[0])
v: list[int] = list(map(int, all_list[1].split()))
v.sort()
min_ans = float('inf')

for first in range(0,n-3):
    for last in range(first+3,n):
        outside_sum = v[first] + v[last]
        s = first + 1
        e = last - 1
        while s <= e:
            inner_sum = v[s] + v[e]
            gap = outside_sum - inner_sum
            if gap == 0:
                print(0)
                exit(0)
            min_ans = min(min_ans, abs(gap))
            # 바깥 합이 더 큰 경우 -> 합을 늘리기 위해 s를 +1
            if gap > 0:
                s += 1
            else:
                e -= 1
            # print(v[first], v[s], v[e], v[last])
print(min_ans)



