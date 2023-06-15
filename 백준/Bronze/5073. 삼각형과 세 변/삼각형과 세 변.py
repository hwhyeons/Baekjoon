
while True:
    a,b,c = map(int,input().split())
    if min(a,b,c) == 0 and max(a,b,c) == 0:
        break
    if max(a,b,c) >= list(sorted([a, b, c]))[1] + min(a,b,c):
        print("Invalid")
    elif len({a, b, c}) == 1:
        print("Equilateral")
    elif len({a, b, c}) == 2:
        print("Isosceles")
    else:
        print("Scalene")