pl: list = list(map(int, input().split())) # ex) 1 2 3 4
tmp = [("+",pl[0]),("-",pl[1]),("*",pl[2]),("/",pl[3])]
abc = sorted(tmp,key= lambda k: k[1],reverse=True)
oper1 = abc[0][0]
oper2 = abc[1][0]
oper3 = abc[2][0]
oper4 = abc[3][0]
line = input()
idx = len(line)-1


def get_token() -> str | None:
    if idx == -1:
        return None
    return line[idx]

def cal(e2: int, e1: int, op: str) -> int:
    if op == "+":
        return e2+e1
    elif op == "-":
        return e2-e1
    elif op == "*":
        return e2*e1
    elif op == "/":
        # C++
        if (e2 < 0 < e1) or (e1 < 0 < e2):
            return -(abs(e2)//abs(e1))
        return e2//e1
    else:
        raise Exception("Improper Operator")

def number() -> int:
    global idx
    if idx == -1:
        raise Exception("err")
    start_idx = idx
    for i in range(start_idx,-1,-1):
        if line[i].isnumeric():
            idx-=1
            continue
        return int(line[i+1:start_idx+1])
    return int(line[:start_idx+1])

def op1() -> int:
    global idx
    num1 = number()
    while True:
        tok = get_token()
        if tok == oper1:
            idx-=1
            num2 = number()
            num1 = cal(num1,num2,oper1)
        else:
            return num1

def op2() -> int:
    global idx
    exp1 = op1()
    while True:
        tok = get_token()
        if tok == oper2:
            idx-=1
            exp2 = op1()
            exp1 = cal(exp1,exp2,oper2)
        else:
            return exp1

def op3() -> int:
    global idx
    exp1 = op2()
    while True:
        tok = get_token()
        if tok == oper3:
            idx-=1
            exp2 = op2()
            # exp1 = exp2 - exp1
            exp1 = cal(exp1,exp2,oper3)
        else:
            return exp1

def op4() -> int:
    global oper4,idx
    exp1 = op3()
    while True:
        tok = get_token()
        if not tok:
            return exp1
        if tok == oper4:
            idx-=1
            exp2 = op3()
            exp1 = cal(exp1,exp2,oper4) # exp1 += exp2
        else:
            return exp1

print(op4())