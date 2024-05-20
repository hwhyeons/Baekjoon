import re
to_custom_int = lambda m: f'Int({m.group(0)})'
def to_python_expression(expression_str) -> str:
    s1 = expression_str.replace("/","//")
    s2 = s1.replace("&&","&")
    s3 = s2.replace("||","|")
    s4 = s3.replace("!","~")
    s5 = re.sub(r'\b\d+\b', to_custom_int, s4)
    return s5

class CodeParser:
    def __init__(self) -> None:
        self.deep = 0
        self.code_str = """\n
class Int(int):
    def __init__(self,val: int):
        self.val = val
    def __add__(self, o):
        return Int(int.__add__(self.val, o.val))
    def __sub__(self, o):
        return Int(int.__sub__(self.val, o.val))
    def __invert__(self):
        return Int(1 if self.val == 0 else 0)
    def __neg__(self):
        return Int(int.__neg__(self.val))
    def __and__(self, o):
        return Int(0) if (o.val == 0 or self.val == 0) else Int(1)
    def __or__(self, o):
        return Int(1) if (o.val != 0 or self.val != 0) else Int(0)
    def __truediv__(self, o):
        return Int(int.__truediv__(self.val, o.val))
    def __floordiv__(self, o):
        return Int(int.__floordiv__(self.val, o.val))
    def __mod__(self, o):
        return Int(int.__mod__(self.val, o.val))
    def __mul__(self, o):
        return Int(int.__mul__(self.val, o.val))
    def __radd__(self, o):
        return Int(int.__radd__(self.val, o.val))
    def __rsub__(self, o):
        return Int(int.__rsub__(self.val, o.val))
    def __rand__(self, o):
        return Int(0) if (o.val == 0 or self.val == 0) else Int(1)
    def __ror__(self, o):
        return Int(1) if (o.val != 0 or self.val != 0) else Int(0)
    def __rmod__(self, o):
        return Int(int.__rmod__(self.val, o.val))
    def __rmul__(self, o):
        return Int(int.__rmul__(self.val, o.val))
    def __rfloordiv__(self, o):
        return Int(int.__rfloordiv__(self.val, o.val))
    def __floor__(self):
        return Int(int.__floor__(self.val))
for ch in 'abcdefghijklmnopqrstuvwxyz':
    exec(f"{ch}=Int(0)")
"""

    def parse_next_line(self, line_strip: str) -> None:
        answer = ''
        indent_add_new = False
        remove_indent = False
        add_pass_line = False
        if line_strip.startswith("print"):
            answer = f'print({to_python_expression(line_strip[5:].strip())})'
        elif line_strip.startswith("set"):
            answer = f'{line_strip[3:].strip()[:line_strip[3:].strip().find("=")]} = {to_python_expression(line_strip[3:].strip()[line_strip[3:].strip().find("=") + 1:])}'
        elif line_strip.startswith("if"):
            indent_add_new = True
            add_pass_line = True
            answer = f'if {to_python_expression(line_strip[2:].strip())}:'
        elif line_strip.startswith("else"):
            remove_indent = True
            add_pass_line = True
            indent_add_new = True
            answer = 'else:'
        elif "end" in line_strip:
            remove_indent = True
        elif line_strip.startswith("while"):
            add_pass_line = True
            indent_add_new = True
            answer = f'while {to_python_expression(line_strip[5:].strip())}:'

        if remove_indent:
            cp.deep-=1
        if not answer:
            return
        final_answer = ' '*4*self.deep+answer
        if indent_add_new: # "다음줄"부터 indent 넣을지
            cp.deep+=1
        self.code_str+=final_answer+"\n"
        if add_pass_line:
            self.code_str+=' '*4*self.deep+"pass\n"

while n:= int(input()):
    cp = CodeParser()
    for _ in range(n):
        cp.parse_next_line(input().strip())
    exec(cp.code_str)
