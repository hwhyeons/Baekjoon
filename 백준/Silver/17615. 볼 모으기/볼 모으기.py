
N = int(input())
s = input()

ans_g = 100000000

def func(check_char: str, reverse: bool):
    global ans_g
    rv_char = 'R' if check_char == 'B' else 'B'
    sig = False
    ans = 0
    check_str = s if not reverse else reversed(s)
    for c in check_str:
        if c == check_char:
            sig = True
            continue
        if c == rv_char and sig:
            ans += 1
    ans_g = min(ans, ans_g)

func(check_char='R',reverse=False)
func(check_char='R',reverse=True)
func(check_char='B',reverse=False)
func(check_char='B',reverse=True)
print(ans_g)