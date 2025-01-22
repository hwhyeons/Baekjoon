import math


def func(v : int,rev: bool):
    # 2^k 찾기
    if v <= 4:
        no_rev = [0,1,1,0][v-1] # 인덱스이므로 -1 처리
        if rev:
            return 1 if no_rev == 0 else 0
        else:
            return no_rev
    k = int(math.log2(v-1))
    closest_2k = 2**k
    gap = v - closest_2k
    return func(gap, not rev)


n = int(input())
print(func(n,False))

# ans = ''
# for n in range(1,17):
#     ans+= str(func(n, False))
# print(ans)
