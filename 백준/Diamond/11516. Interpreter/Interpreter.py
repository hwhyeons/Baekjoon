import re
pattern_custom_int = r'\b\d+\b'
def to_custom_int(match):
    return f'Int({match.group(0)})'

class Expression:

    @staticmethod
    def to_python_expression(expression_str) -> str:
        # 1. 나누기 -> // 로
        s1 = expression_str.replace("/","//")
        s2 = s1.replace("&&","&")
        s3 = s2.replace("||","|")
        s4 = s3.replace("!","~")
        s5 = re.sub(pattern_custom_int, to_custom_int, s4)
        return s5

class CodeParser:
    def __init__(self) -> None:
        self.deep = 0
        self.code_str = """\n
class Int(int):
    def __init__(self,value: int):
        self.value = value
    def __invert__(self):
        if self.value == 0:
            return Int(1)
        else:
            return Int(0)

    def __neg__(self):
        return Int(int.__neg__(self.value))
    def __add__(self, other):
        return Int(int.__add__(self.value, other.value))
    def __sub__(self, other):
        return Int(int.__sub__(self.value, other.value))
    def __and__(self, other):
        return Int(0) if (other.value == 0 or self.value == 0) else Int(1)
    def __or__(self, other):
        return Int(1) if (other.value != 0 or self.value != 0) else Int(0)
    def __eq__(self, other):
        return Int(int.__eq__(self.value, other.value))
    def __ne__(self, other):
        return Int(int.__ne__(self.value, other.value))
    def __lt__(self, other):
        return Int(int.__lt__(self.value, other.value))
    def __le__(self, other):
        return Int(int.__le__(self.value, other.value))
    def __gt__(self, other):
        return Int(int.__gt__(self.value, other.value))
    def __ge__(self, other):
        return Int(int.__ge__(self.value, other.value))
    def __xor__(self, other):
        return Int(int.__xor__(self.value, other.value))
    def __lshift__(self, other):
        return Int(int.__lshift__(self.value, other.value))
    def __rshift__(self, other):
        return Int(int.__rshift__(self.value, other.value))
    def __truediv__(self, other):
        return Int(int.__truediv__(self.value, other.value))
    def __floordiv__(self, other):
        return Int(int.__floordiv__(self.value, other.value))
    def __mod__(self, other):
        return Int(int.__mod__(self.value, other.value))
    def __mul__(self, other):
        return Int(int.__mul__(self.value, other.value))
    def __pow__(self, other):
        return Int(int.__pow__(self.value, other.value))
    def __radd__(self, other):
        return Int(int.__radd__(self.value, other.value))
    def __rsub__(self, other):
        return Int(int.__rsub__(self.value, other.value))
    def __rand__(self, other):
        return Int(0) if (other.value == 0 or self.value == 0) else Int(1)
    def __ror__(self, other):
        return Int(1) if (other.value != 0 or self.value != 0) else Int(0)
    def __rxor__(self, other):
        return Int(int.__rxor__(self.value, other.value))
    def __rshift__(self, other):
        return Int(int.__rshift__(self.value, other.value))
    def __rtruediv__(self, other):
        return Int(int.__rtruediv__(self.value, other.value))
    def __rfloordiv__(self, other):
        return Int(int.__rfloordiv__(self.value, other.value))
    def __rmod__(self, other):
        return Int(int.__rmod__(self.value, other.value))
    def __rmul__(self, other):
        return Int(int.__rmul__(self.value, other.value))
    def __rpow__(self, other):
        return Int(int.__rpow__(self.value, other.value))
    def __rshift__(self, other):
        return Int(int.__rshift__(self.value, other.value))
    def __rtruediv__(self, other):
        return Int(int.__rtruediv__(self.value, other.value))
    def __rfloordiv__(self, other):
        return Int(int.__rfloordiv__(self.value, other.value))
    def __abs__(self):
        return Int(int.__abs__(self.value))
    def __ceil__(self):
        return Int(int.__ceil__(self.value))
    def __floor__(self):
        return Int(int.__floor__(self.value))
    def __round__(self):
        return Int(int.__round__(self.value))
    def __trunc__(self):
        return Int(int.__trunc__(self.value))
    def __index__(self):
        return Int(int.__index__(self.value))


a=Int(0)
b=Int(0)
c=Int(0)
d=Int(0)
e=Int(0)
f=Int(0)
g=Int(0)
h=Int(0)
i=Int(0)
j=Int(0)
k=Int(0)
l=Int(0)
m=Int(0)
n=Int(0)
o=Int(0)
p=Int(0)
q=Int(0)
r=Int(0)
s=Int(0)
t=Int(0)
u=Int(0)
v=Int(0)
w=Int(0)
x=Int(0)
y=Int(0)
z=Int(0)
"""


    def convert_print(self, line_strip: str):
        expression_str: str = line_strip[5:].strip()
        return f'print({Expression.to_python_expression(expression_str)})'

    def convert_set(self, line_strip: str):
        # 맨앞 set 제거
        # set n = expr~
        assert line_strip.startswith("set")
        s1 = line_strip[3:] # n = expr ~
        s2 = s1.strip()
        equal_index = s2.find('=') # 첫번째 할당자
        left_var_name = s2[:equal_index]
        right_expression = s2[equal_index+1:]
        right_expression_cvt = Expression.to_python_expression(right_expression)
        final_expression = f'{left_var_name} = {right_expression_cvt}'
        return final_expression

    def convert_if(self, line: str):
        assert line.startswith("if")
        #ex) if n % 2 ==0

        s1 = line[2:].strip() # "n % 2 == 0"
        expression_without_if = Expression.to_python_expression(s1)
        full_str = f'if {expression_without_if}:'
        return full_str

    def convert_else(self, line: str):
        assert line.startswith("else")
        else_str = f'else:'
        return else_str

    def convert_while(self, line: str):
        assert line.startswith("while")
        s1 = line[5:].strip() # "n % 2 == 0"
        expression_without_while = Expression.to_python_expression(s1)
        full_str = f'while {expression_without_while}:'
        return full_str

    def add_indent(self) -> None:
        self.deep +=1

    def remove_indent(self) -> None:
        self.deep -= 1
        assert self.deep >= 0

    def add_space(self,line: str):
        assert line[0] != ' '
        return ' '*4*self.deep+line


    def parse_next_line(self, line_strip: str) -> None:
        answer = ''
        indent_add_new = False
        remove_indent = False
        add_pass_line = False
        if line_strip.startswith("print"):
            answer = self.convert_print(line_strip)
        elif line_strip.startswith("set"):
            answer = self.convert_set(line_strip)
        elif line_strip.startswith("if"):
            indent_add_new = True
            add_pass_line = True
            answer = self.convert_if(line_strip)
        elif line_strip.startswith("else"):
            remove_indent = True
            add_pass_line = True
            indent_add_new = True
            answer = self.convert_else(line_strip)
        elif "end" in line_strip:
            remove_indent = True
        elif line_strip.startswith("while"):
            add_pass_line = True
            indent_add_new = True
            answer = self.convert_while(line_strip)
        else:
            raise Exception("No Case Error")
        

        # else는 한번 indent 줄여야함
        if remove_indent:
            cp.remove_indent()

        # end if 같은 없는 라인
        if not answer:
            return
        # 마지막으로 스페이스바 추가
        final_answer = self.add_space(answer)
        if indent_add_new: # "다음줄"부터 indent 넣을지
            cp.add_indent()
        self.code_str+=final_answer+"\n"
        if add_pass_line:
            self.code_str+=self.add_space("pass")+"\n"

while True:
    cp = CodeParser()
    n = int(input())
    if n == 0:
        break
    for _ in range(n):
        strip_line: str = input().strip()
        cp.parse_next_line(strip_line)
    exec(cp.code_str)
