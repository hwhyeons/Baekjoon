from fractions import Fraction
# f1 = 1
# f2 = Fraction(2,3)
# ans = (f1+f2)
# print(ans.numerator)
# print(ans.denominator)

# len_line = int(input())
input()
line = input()
idx= 0

if line[0] != "(" or line[-1] != ")":
    print(-1)
    exit(0)

# line = line[2:-2]
len_line = len(line)

def cal_fraction(a,b,c) -> Fraction:
    return a + Fraction(b,c)

def error():
    print(-1)
    exit(-1)

def dfs(depth) -> Fraction:
    global idx,line
    three: list[Fraction] = []
    while True:
        if depth == 0 and len(three) == 1:
            return three[0]

        # if len(three) == 3:
        #     answer = cal_fraction(*three)
        #     if idx+2 >= len_line or line[idx+2] != ")":
        #         print(-1)
        #         exit(0)
        #     idx+=2
        #     return answer
        if idx >= len_line:
            print(-1)
            exit(0)
        c = line[idx]
        if c == "(":
            if idx+2 >= len_line or line[idx+2] == ")":
                error()
            idx+=2
            three.append(dfs(depth+1))
            idx+=2
        elif c == ")":
            if len(three) != 3:
                print(-1)
                exit(0)
            answer = cal_fraction(*three)
            return answer
        else: # 숫자
            three.append(Fraction(int(line[idx:idx + 2]),1))
            idx+=2




f_ans = dfs(0)
if idx < len_line:
    print(-1)
    exit(0)
print(f_ans.numerator,f_ans.denominator)

