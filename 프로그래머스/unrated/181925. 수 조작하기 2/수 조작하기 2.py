def solution(numLog):
    return ''.join([['w','a',1,'d','s'][(numLog[i]-numLog[i-1])%6-1] for i in range(1,len(numLog))])