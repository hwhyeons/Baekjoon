s = input()

stk = [] # 스택
tf_tag = False
for i in range(len(s)):
    c = s[i]
    if c == '<':
        print(''.join(reversed(stk)),end='')
        stk.clear()
        tf_tag = True
        print('<',end='')
        continue
    elif c == '>':
        assert tf_tag
        tf_tag = False
        print('>',end= '')
        continue
    if tf_tag:
        print(c,end='')
        continue
    if c == ' ':
        print(''.join(reversed(stk)),end=' ')
        stk.clear()
    else:
        stk.append(c)

if stk:
    print(''.join(reversed(stk)),end=' ')