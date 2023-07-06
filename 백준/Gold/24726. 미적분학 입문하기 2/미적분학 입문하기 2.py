import math
from collections import namedtuple

x1,y1,x2,y2,x3,y3 = map(float,input().split())
tps = [(x1,y1),(x2,y2),(x3,y3)]
tps.sort(key=lambda x : x[0])
x1,y1 = tps[0]
x2,y2 = tps[1]
x3,y3 = tps[2]

# fx = lambda x1,y1,x2,y2 :
# fy = ;

def get_area(x1,y1,x2,y2):
    if x2 == x1:
        return 0.0

    # y = ax+b
    a = (y2-y1)/(x2-x1)
    b = (y2-y1)/(x2-x1)*-1*x1 + y1

    # 적분 식
    FY = lambda x : (a**2)/3 * (x**3) + a*b*(x**2) + b*b*x
    F_VAL = FY(x2) - FY(x1)
    return math.pi*F_VAL


Line = namedtuple('Line',['x1','y1','x2','y2'])
# l1 = Line(x1,y1,x2,y2)
# l2 = Line(x1,y1,x3,y3)
# l3 = Line(x2,y2,x3,y3)

area1 = get_area(x1,y1,x3,y3)
area2 = get_area(x1,y1,x2,y2)
area3 = get_area(x2,y2,x3,y3)
area_rev_1 = get_area(y1,x1,y3,x3)
area_rev_2 = get_area(y1,x1,y2,x2)
area_rev_3 = get_area(y2,x2,y3,x3)
print(abs(area1-area2-area3),abs(area_rev_1-area_rev_2-area_rev_3))


