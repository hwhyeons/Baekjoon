def solution(arr, queries):
    for a,b in queries:
        k[a],k[b]=(k:=arr)[b],k[a]
    return arr