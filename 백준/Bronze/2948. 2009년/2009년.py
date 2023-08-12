import datetime
print(['Mon','Tues','Wednes','Thurs','Fri','Satur','Sun'][datetime.date(2009,*reversed(list(map(int,input().split())))).weekday()]+"day")