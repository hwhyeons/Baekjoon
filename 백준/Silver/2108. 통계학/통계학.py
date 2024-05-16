import statistics
N = int(input())
v = []
for i in range(N):
    v.append(int(input()))
print(round(statistics.mean(v)))
print(statistics.median(v))
print(t[1] if len(t:=sorted(statistics.multimode(v)))> 1 else t[0])
print(max(v)-min(v))