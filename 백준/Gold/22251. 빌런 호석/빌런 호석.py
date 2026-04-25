import functools


arr=["1110111",
"0010010",
"1011101",
"1011011",
"0111010",
"1101011",
"1101111",
"1010010",
"1111111",
"1111011"]

N,K,P,X = map(int, input().split())

def add_prefix(num_str):
    if len(num_str) < K:
        return "0"*(K-len(num_str))+num_str
    return num_str

@functools.cache
def convert_char(c1,c2):
    # 리턴값:반전한LED수;
    assert len(c1) == 1 and len(c2) == 1
    n_a = int(c1)
    n_b = int(c2)
    s1=arr[n_a]
    s2=arr[n_b]
    diff_cnt = 0
    for idx in range(7):
        if s1[idx]!=s2[idx]:
            diff_cnt+=1
    return diff_cnt




def convert(origin: int, after: int) -> bool:
    origin_str = str(origin)
    # K자리 만들기
    origin_str = add_prefix(origin_str)
    after = add_prefix(str(after))
    # print(origin_str)
    # print(after)
    # print("---")
    # 한자리 한자리 만들기
    use_led = 0
    assert len(origin_str) == len(after)
    for idx in range(K):
        use_led+=convert_char(origin_str[idx],after[idx])
        if use_led > P:
            return False
    if use_led == 0:
        return False # 반전에 실패한 경우
    return True




ans = 0
for candidate in range(1,N+1):
    # candidate : 바꿀 후보군
    # 기본값 그대로
    if candidate == X:
        continue
    success = convert(X,candidate)
    if success:
        ans+=1
print(ans)