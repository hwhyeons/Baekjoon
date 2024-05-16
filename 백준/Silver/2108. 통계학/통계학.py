import statistics
v = [*map(int,open(0))][1:]
print(round(statistics.mean(v)))
print(statistics.median(v))
print(t[1] if len(t:=sorted(statistics.multimode(v)))> 1 else t[0])
print(max(v)-min(v))