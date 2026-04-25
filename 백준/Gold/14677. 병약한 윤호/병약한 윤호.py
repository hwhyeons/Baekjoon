import functools,sys
sys.setrecursionlimit(2**15)
n,all=input(),input()
d={'B':'L','L':'D','D':'B'}

@functools.cache
def f(s, e, k):
    if s==e:
        return 0 if all[s] == k else -1
    if all[s]==k and all[e]==k:
        return max(f(s + 1, e, d[k]), f(s, e - 1, d[k]))+1
    return f(s + 1, e, d[k])+1 if all[s]==k else f(s, e - 1, d[k])+1 if all[e]==k else -1

print(f(0,len(all)-1,'B')+1)

