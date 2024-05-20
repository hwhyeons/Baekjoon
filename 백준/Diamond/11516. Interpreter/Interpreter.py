import re
to_int = lambda m: f'Int({m.group(0)})'
def to_python_expression(exp):
    return re.sub(r'\b\d+\b', to_int, exp.replace("/", "//").replace("&&", "&").replace("||", "|").replace("!", "~"))
deep=0
org = """\n
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

def parse_line(ls):
    global deep,code_str
    ans = ''
    new_ind = 0
    psline = 0
    if ls.startswith("print"):
        ans = f'print({to_python_expression(ls[5:].strip())})'
    elif ls.startswith("set"):
        ans = f'{ls[3:].strip()[:ls[3:].strip().find("=")]} = {to_python_expression(ls[3:].strip()[ls[3:].strip().find("=") + 1:])}'
    elif ls.startswith("if"):
        new_ind = 1
        psline = 1
        ans = f'if {to_python_expression(ls[2:].strip())}:'
    elif ls.startswith("else"):
        deep-=1
        psline = 1
        new_ind = 1
        ans = 'else:'
    elif "end" in ls:
        deep-=1
        return
    elif ls.startswith("while"):
        psline = 1
        new_ind = 1
        ans = f'while {to_python_expression(ls[5:].strip())}:'
    final_answer = ' '*4*deep+ans
    deep+=new_ind
    code_str+=final_answer+"\n"
    if psline:
        code_str+=' '*4*deep+"pass\n"

while n:= int(input()):
    code_str=org;deep=0
    for _ in range(n):
        parse_line(input().strip())
    exec(code_str)
