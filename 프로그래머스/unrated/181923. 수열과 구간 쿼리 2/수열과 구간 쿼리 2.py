def solution(arr, queries):
    return [min(t) if len((t:=list(filter(lambda x:x>q[2],arr[q[0]:q[1]+1]))))>1 else -1 if len(t)==0 else t[0] for q in queries]
