
cas = 0
while 1:
    cas+=1
    n = int(input())
    if n == 0:
        break
    print(f"Case {cas}:")
    print(f"{n} pencils for {n} cents")
    flag = False
    for four in range(1,n):
        for second in range(1,n):
            for one in range(1,n):
                if four+second+one != n:
                    continue
                money = four*4 + second/2 + one/4
                if money == n:
                    print(f"{four} at four cents each")
                    print(f"{second} at two for a penny")
                    print(f"{one} at four for a penny\n")
                    flag = True
    if not flag:
        print("No solution found.\n")


