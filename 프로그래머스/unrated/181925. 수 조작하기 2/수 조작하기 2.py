def solution(numLog):
    return ''.join([{1:'w',-1:'s',10:'d',-10:'a'}[numLog[i]-numLog[i-1]] for i in range(1,len(numLog))])