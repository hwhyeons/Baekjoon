import re
to_custom_int = lambda m: f'Int({m.group(0)})'
def to_python_expression(expression_str):
    s1 = expression_str.replace("/","//")
    s2 = s1.replace("&&","&")
    s3 = s2.replace("||","|")
    s4 = s3.replace("!","~")
    s5 = re.sub(r'\b\d+\b', to_custom_int, s4)
    return s5

class CodeParser:
    def __init__(self):
        self.deep = 0
        self.code_str = """\n
class Int(int):
    def __init__(self,val: int):
        self.val = val
    def __add__(self, o):
        return Int(self.val+o.val)
    def __sub__(self, o):
        return Int(self.val-o.val)
    def __mul__(self, o):
        return Int(self.val*o.val)
    def __invert__(self):
        return Int(1 if self.val == 0 else 0)
    def __neg__(self):
        return Int(int.__neg__(self.val))
    def __and__(self, o):
        return Int(0) if (o.val == 0 or self.val == 0) else Int(1)
    def __or__(self, o):
        return Int(1) if (o.val != 0 or self.val != 0) else Int(0)
    def __floordiv__(self, o):
        return Int(self.val//o.val)
    def __mod__(self, o):
        return Int(self.val%o.val)
for ch in 'abcdefghijklmnopqrstuvwxyz':
    exec(f"{ch}=Int(0)")
"""

    def parse_next_line(self, ls):
        ans = ''
        new_ind = False
        r_ind = False
        psline = False
        if ls.startswith("print"):
            ans = f'print({to_python_expression(ls[5:].strip())})'
        elif ls.startswith("set"):
            ans = f'{ls[3:].strip()[:ls[3:].strip().find("=")]} = {to_python_expression(ls[3:].strip()[ls[3:].strip().find("=") + 1:])}'
        elif ls.startswith("if"):
            new_ind = True
            psline = True
            ans = f'if {to_python_expression(ls[2:].strip())}:'
        elif ls.startswith("else"):
            r_ind = True
            psline = True
            new_ind = True
            ans = 'else:'
        elif "end" in ls:
            r_ind = True
        elif ls.startswith("while"):
            psline = True
            new_ind = True
            ans = f'while {to_python_expression(ls[5:].strip())}:'
        if r_ind:
            cp.deep-=1
        if not ans:
            return
        final_answer = ' '*4*self.deep+ans
        if new_ind:
            cp.deep+=1
        self.code_str+=final_answer+"\n"
        if psline:
            self.code_str+=' '*4*self.deep+"pass\n"

while n:= int(input()):
    cp = CodeParser()
    for _ in range(n):
        cp.parse_next_line(input().strip())
    exec(cp.code_str)
