from collections import Counter
v=[]
try:
    while True:
        s = input()
        v.extend(s.split())
except:
    c = Counter(sorted(v))
    d = dict()
    for k,v in c.items():
        d[k] = [v,0]
    all_cnt = sum(c.values())
    for key in d:
        d[key][1] = d[key][0]/all_cnt
    orders = ['Re','Pt','Cc','Ea','Tb','Cm','Ex']
    for order in orders:
        if not order in d:
            d[order] = [0]*2
        print('{} {} {:.2f}'.format(order,d[order][0],d[order][1]))
    print(f"Total {all_cnt} 1.00")

