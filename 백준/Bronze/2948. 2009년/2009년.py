from datetime import date
a,b=map(int,input().split())
print(['Monday','Tuesday','Wednesday','Thursday','Friday','Saturday','Sunday'][date(2009,b,a).weekday()])