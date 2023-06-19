# import sys
# sys.setrecursionlimit(10**6)

s = 0

oper = ["+","-","*","/"]

fin_read = False


# ")"를 만날 때는 s 증가 X
def getTok():
    global s,line,fin_read
    if s>=len(line): # 끝난 경우
        fin_read = True
        return
    c = line[s]
    if c in oper:
        s+=1
    elif c == "(":
        s+=1
    elif c == ")":
        s+=1
    else: # 숫자
        e = s+1
        while True:
            if e >= len(line) or (not line[e].isnumeric()):
                rt = int(line[s:e])
                s=e
                return rt
            else:
                e+=1

    return c


def revTok():
    global s,fin_read
    if fin_read:
        return
    else:
        s-=1




def error():
    print("ROCK")
    exit(0)

def isOperator(tok):
    global oper
    if tok in oper:
        return True
    else:
        return False


# oper : +,-,*,/
def cal(left:int,right:int,oper:str):
    if oper == "+":
        return left+right
    elif oper == "-":
        return left-right
    elif oper == "*":
        return left*right
    elif oper == "/":
        if right == 0: # divide zero
            error()
        else:
            return left//right
    else:
        error()
        # raise Exception("not operator")




def factor():
    tok = getTok()
    if tok == "(":
        exp = express()
        tok2 = getTok()
        if tok2 == ")": # 주의! 여기서는 None이라고 해서 절대 넘기면 안됨. 무조건 ")"이 나와야하기 때문
            return exp
        else:
            error()
    elif type(tok) == int:
        return tok
    else:
        error()


def term():
    ans = factor()
    while True:
        nt = getTok()
        if nt == "*" or nt == "/":
            ft = factor()
            ans = cal(ans,ft,nt)
        else:
            revTok()
            break
    return ans



# return : 숫자
def express():
    global s
    ans = term()
    while True:
        nt = getTok()
        if nt == "+" or nt == "-":
            t = term()
            ans = cal(ans,t,nt)
        else:
            revTok()
            break
    return ans

if __name__ == '__main__':
    line = input()
    ans = express()
    if not fin_read:
        error()
    print(ans)





