i = 1
while True:
    s = input()
    if s.__contains__("E"):
        break
    print(f"Case {i}: {str(eval(s)).lower()}")
    i+=1
